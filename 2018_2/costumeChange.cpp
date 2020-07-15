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
int N;
vector<vector<pair<int,int>>> costume;
vector<vector<int>> graph;
vector<bool> seen;
vector<int> matched;

bool compute(int point){
    for(int v=1;v<=N;++v){
        if( graph[point][v] && seen[v]==false){
            seen[v]=true;
            if(matched[v]==-1 || compute(matched[v])){
                matched[v]=point;
                return true;
            }
        }
    }
    return false;
    
}

int match(int cloth){
    vector<vector<int>> v2(N+1,vector<int>(N+1,0));
    graph=v2;
    vector<int> v4(N+1,-1);
    matched=v4;
    for(pair<int,int> p: costume[cloth]){
        graph[p.first][p.second]=1;
    }
    int answer=0;
    for(int i=1;i<=N;++i){
        vector<bool> v3(N+1,false);
        seen=v3;
        if(compute(i)){answer++;}
    }
    return answer;
}

int main(){
    int T;
    cin>>T;
    int clothes;

    for(int tt=1;tt<T+1;++tt){
        cin>>N;  
        vector<vector<pair<int,int>>> v1(2*N+1);
        costume=v1;
        
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                cin>>clothes;
                costume[clothes+N].push_back(make_pair(i,j));
            } 
            
        }
        int result=0;
        for(int i=0;i<=2*N;++i){
            if(i==N){continue;}
            result+=costume[i].size()-match(i);
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;

    }
}
