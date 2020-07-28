#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;

struct node{
    int selection;
    vector<int> number;

    node(int select, vector<int> count){
        selection=select;
        number=count;
    }

    bool operator==(const node & d) const{
        return selection==d.selection && number==d.number;
    }
};

namespace std{
    template<>
    struct hash<node>{
        size_t operator()(const node & d) const{
            auto ic=hash<int>();
            size_t uniqueKey=d.selection;
            for(int num:d.number){
                uniqueKey=(uniqueKey<<1) ^ (ic(num));
            }
            return uniqueKey;
        }
    };
}

int N;
int M;
vector<vector<int>> graph;
vector<bool>visited;
unordered_map<node, unordered_map<int,int>> lookup;
vector<pair<int,int>> children;
vector<int> bound;
vector<int> quantity;

void init(){
    vector<vector<int>> v1(2*N);
    graph=v1;
    vector<bool>v2(2*N,false);
    visited=v2;

    lookup.clear();
    children.clear();
    bound.clear();
}

void compute(int selection){
    int totalLeft=0;
    int totalRight=0;
    for(int k=0;k<M;++k){
        if(selection & (1<<k) ) {totalLeft+=(children[k].first)*quantity[k]; 
            totalRight+=(children[k].second)*quantity[k];
        }
    }
    node myNode(selection, quantity);
    for(auto x:lookup[myNode]){
        int possN=x.first;
        int current=x.second;
        int r1=totalLeft-possN;
        int r2=totalRight-possN;
        for(int p=0;p<M;++p){
            if(quantity[p]<bound[p]){
                int s1=children[p].first;
                int s2=children[p].second;
                int newVal= (selection | (1<<p));
                vector<int> newV=quantity;
                newV[p]++;
                int newN=possN;
                int newP=current;
                node newNode(newVal, newV);
                if(r1+s1==r2+s2){newN+=r1+s1;newP+=(r1+s1)*(r1+s1);}
                if(lookup.find(newNode)==lookup.end() || lookup[newNode].find(newN)==lookup[newNode].end()){
                    lookup[newNode][newN]=newP;
                }
                else{lookup[newNode][newN]=min(newP,lookup[newNode][newN]);}
            }
            
        }
    }
    for(int j=0;j<M;++j){
        if( (selection & (1<<j)) && quantity[j]<bound[j]) //sequence might be reversed
        {
            quantity[j]++;
            for(int k=0;k<j;++k){if(selection & (1<<k)) {quantity[k]=1;}}  
            return compute(selection);
        }
    }
}

pair<int,int> dfs(int u){
    if(visited[u]){return {0,0};}
    visited[u]=true;
    int left=0;
    int right=0;
    if(u<N){left++;}
    else{right++;}
    for(int k:graph[u]){
        if(!visited[k]){
            pair<int,int> ans=dfs(k);
            left+=ans.first;
            right+=ans.second;
        }
    }
    return make_pair(left,right);
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        init();
        int e=0;
        for(int i=0;i<N;++i){
            string line;
            cin>>line;
            for(int j=0;j<N;++j){
                if(line[j]=='1'){graph[i].push_back(N+j); graph[N+j].push_back(i); e++; }
            }
        }
        pair<int,int> ans;
        unordered_map<int,unordered_map<int,int>> childCount;
        for(int i=0;i<2*N;++i){
            if(!visited[i]){
                ans=dfs(i);
                childCount[ans.first][ans.second]++;
            }
        }
        
        for(auto x: childCount){
            for(auto y:x.second){
                children.push_back({x.first,y.first});
                bound.push_back(y.second);
            } 
        }
        M=children.size();
        
        //deal with i==0
        for(int i=0;i<M;++i){
            int s=(1<<i);
            vector<int> starter(M,0);
            starter[i]=1;
            node iNode(s,starter);
            if(children[i].first==children[i].second){
                int n1=children[i].first;
                lookup[iNode][n1]=n1*n1;
            }
            else{lookup[iNode][0]=0;}   
        }

        for(int i=1;i<(1<<M);++i){
            vector<int> starter(M,0);
            for(int j=0;j<M;++j){
                if( i& (1<<j) ){starter[j]=1;}
            }
            quantity=starter;
            compute(i);   
        }

        node r((1<<M)-1, bound);
        int result=lookup[r][N]-e;
        cout<<"Case #"<<tt<<": "<<result<<endl;
        
    }
}
