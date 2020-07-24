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

int N;
vector<unordered_set<int>>graph;
vector<unordered_set<int>>bGraph;
vector<int> discover;

vector<int> pointStack;
unordered_set<int> inStack;
unordered_set<int> cycle;

void init(){
    vector<unordered_set<int>>v2(N);
    graph=v2;
    bGraph=v2;
    vector<int> v1(N,-1);
    discover=v1;
}

int dfs(int u){
    discover[u]=1;
    int height=1;
    for(int n:bGraph[u]){
        if(cycle.find(n)!=cycle.end() || discover[n]!=-1){continue;}
        height=max(height,dfs(n)+1);
    }
    return height;
}

bool findCycle(int u){
    if(inStack.find(u)!=inStack.end()){
        while(pointStack.back()!=u){
            cycle.insert(pointStack.back());
            pointStack.pop_back();
        }
        cycle.insert(u);
        pointStack.pop_back();
        return true;
    }
    pointStack.push_back(u);
    inStack.insert(u);
    for(int neighbor:graph[u]){
        if(findCycle(neighbor)){return true;}
    }
    pointStack.pop_back();
    inStack.erase(u);
    return false;
}

int main(){
    int T;
    cin>>T;
    int BFF;

    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        init();
        for(int i=0;i<N;++i){
            cin>>BFF;
            graph[i].insert(BFF-1);
            bGraph[i].insert(BFF-1);
            bGraph[BFF-1].insert(i);
        }
      
        int result=0;
        int twosGroup=0;
        for(int i=0;i<N;++i){
            if(discover[i]==-1){
                pointStack.clear();
                inStack.clear();
                cycle.clear();
                findCycle(i);
                if(cycle.size()>2){result=max(result,(int)cycle.size());}
                int m1=0;
                int m2=0;
                for(int j:cycle){
                    int height=dfs(j)-1;
                    if(height>m2){m2=height;}
                    if(m2>m1){swap(m1,m2);}
                }
                if(cycle.size()==2){twosGroup+=m1+m2+2;}
            }
        }

        cout<<"Case #"<<tt<<": "<<max(twosGroup, result)<<endl;
        
    }
}
