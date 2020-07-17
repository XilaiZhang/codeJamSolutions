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
int N,M;
vector<vector<char>> oldGrid;
vector<vector<int>> hGrid;
vector<vector<int>> dGrid;
vector<vector<char>> newGrid;
vector<bool> seenRow;
vector<bool> seenCol;
vector<bool> seenDiagnol;
vector<bool> seenAntidiagnol;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> matched;


void init(){
    vector<vector<char>> v1(N+1, vector<char>(N+1,'.'));
    newGrid=v1;
    oldGrid=v1;
    vector<vector<int>> v2(N+1, vector<int>(N+1));
    hGrid=v2;
    dGrid=v2;
    vector<bool> v3(N+1,false);
    seenRow=v3;
    seenCol=v3;
    vector<vector<int>> v4(2*N-1);
    graph=v4;
    vector<int> v5(2*N-1,-1);
    matched=v5;
    vector<bool> v6(2*N-1,false);
    seenDiagnol=v6;
    seenAntidiagnol=v6;
}

bool compute(int point){
    for(int v:graph[point]){
        if(!visited[v]){
            visited[v]=true;
            if(matched[v]<0 || compute(matched[v])){
                matched[v]=point;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    char type;
    int R,C;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>M;
        init();
        for(int i=0;i<M;++i){
            cin>>type;
            cin>>R>>C;
            oldGrid[R][C]=type;
            if(type=='+'){
                seenDiagnol[R-C+N-1]=true;
                seenAntidiagnol[R+C-2]=true;
                graph[R-C+N-1]={R+C-2};}
            else if(type=='x'){hGrid[R][C]=1;seenRow[R]=true;seenCol[C]=true;}
            else{
                seenDiagnol[R-C+N-1]=true;
                seenAntidiagnol[R+C-2]=true;
                hGrid[R][C]=1;seenRow[R]=true;seenCol[C]=true;
                graph[R-C+N-1]={R+C-2};
            }
        }

        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(!seenDiagnol[i-j+N-1] && ! seenAntidiagnol[i+j-2]){
                    graph[i-j+N-1].push_back(i+j-2);
                } 
            }
        }

        for(int i=1;i<=N;++i){
            if(seenRow[i]){continue;}
            for(int j=1;j<=N;++j){
                if(!seenCol[j]){
                    hGrid[i][j]=1;
                    seenRow[i]=true;
                    seenCol[j]=true;
                    break;
                }
            }
        }
        
        for(int i=0;i<2*N-1;++i){
            vector<bool> allFalse(2*N-1,false);
            visited=allFalse;
            compute(i);
        }

        int y=0;
        for(int b=0;b<2*N-1;++b){
            if(matched[b]>=0){
                int a=matched[b];
                int x=(a+b+3-N)/2;
                int y=(b-a+N+1)/2;
                dGrid[x][y]=1;
            }
        }

        int z=0;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(hGrid[i][j]){newGrid[i][j]='x';}
                if(dGrid[i][j]){
                    if(newGrid[i][j]=='x'){newGrid[i][j]='o';}
                    else{newGrid[i][j]='+';}
                }
                if(oldGrid[i][j]!=newGrid[i][j]){
                    z++;
                }
                
                if(newGrid[i][j]=='x' || newGrid[i][j]=='+'){y++;}
                else if(newGrid[i][j]=='o'){y+=2;}
            }
        }
        cout<<"Case #"<<tt<<": "<<y<<" "<<z<<endl;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                if(oldGrid[i][j]!=newGrid[i][j]){
                    cout<<newGrid[i][j]<<" "<<i<<" "<<j<<endl;
                }
            }
        }

    }
}
