#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>

using namespace std;
long long mod=1e9+7;
int M;
vector<vector<int>> graph;
vector<vector<int>> G;
vector<int> inStack;
vector<int> pointStack;
vector<int> discover;
vector<int> low;
vector<int> sccNumber;
int seq;
int sccSeq;
vector<long long> ways;

void init(){ //check pointStack
    graph.clear();
    G.clear();
    vector<vector<int>> v1(M+1);
    graph=v1;
    G=v1;
    vector<int>v2(M+1,0);
    discover=v2;
    low=v2;
    sccNumber=v2;
    pointStack=v2;
    inStack=v2;
    seq=1;
    sccSeq=1;
    vector<long long>v3(M+1,-1);
    ways=v3;
}

long long compute(long long point, unordered_set<int> & seen){
    if(ways[point]!=-1){return ways[point];}
    long long answer=0;
    if(seen.find(G[point][0])!=seen.end()){
        answer=compute(G[point][0],seen);
    }
    if(seen.find(G[point][1])!=seen.end()){
        answer=(answer+compute(G[point][1],seen))%mod;
    }
    ways[point]=answer;
    return answer;
}

void findScc(int u){
    inStack[u]=1;
    discover[u]=seq;
    low[u]=seq;
    pointStack.push_back(u);
    seq++;
    for(int neighbor:graph[u]){
        if(!discover[neighbor]){
            findScc(neighbor);
            low[u]=min(low[u],low[neighbor]);
        }
        else if(inStack[neighbor]){  //the neighbor is in stack
            low[u]=min(low[u],discover[neighbor]);
        }
    }
    int w=-1;
    if(low[u]==discover[u]){
        while(w!=u){
            w=pointStack.back();
            pointStack.pop_back();
            sccNumber[w]=sccSeq;
            inStack[w]=0;
        }
        sccSeq++;
    }
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        cin>>M;
        init();
        
        vector<long long>Q(M+1);

        for(int i=1;i<=M;++i){
            int R1,R2;
            cin>>R1>>R2;
            G[i].push_back(R1);
            G[i].push_back(R2);
            graph[R1].push_back(i);
            graph[R2].push_back(i);
        }
        for(int i=1;i<=M;++i){
            cin>>Q[i];
        }
        unordered_set<int>seen;
        list<int>q={1};
        while(!q.empty()){
            int point=q.front();
            q.pop_front();
            if(seen.find(point)!=seen.end()){continue;}
            seen.insert(point);
            for(int neighbor: graph[point]){
                q.push_back(neighbor);
            }
        }
        
        for(int i=1;i<=M;++i){
            if(!discover[i]){
                findScc(i);
            }     
        }

        unordered_set<int> prev;
        q.clear();
        for(int i=1;i<=M;++i){
            if(Q[i]>0){q.push_back(i);}     
        }
        while(!q.empty()){
            int point=q.front();
            q.pop_front();
            if(prev.find(point)!=prev.end()){continue;}
            prev.insert(point);
            for(int neighbor: G[point]){
                q.push_back(neighbor);
            }
        }

        bool done=false;
        for(int i=1;i<=M;++i){
            int R1=G[i][0];
            int R2=G[i][1];
            if( (seen.find(R1)!=seen.end()) && (sccNumber[R2]==sccNumber[i]) && (prev.find(i)!=prev.end())){
                done=true;
                break;
            }
            if( (seen.find(R2)!=seen.end()) && (sccNumber[R1]==sccNumber[i]) && (prev.find(i)!=prev.end())){
                done=true;
                break;
            }
        }
        if(done){
            cout<<"Case #"<<tt<<": UNBOUNDED"<<endl; 
            continue;
        }

        long long result=0;
        ways[1]=1;

        for(long long i=1;i<=M;++i){
            if(Q[i]==0){continue;}
            compute(i,seen);
            result=(result+(ways[i]*Q[i])%mod)%mod;
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;   
        
        
    }  
}
