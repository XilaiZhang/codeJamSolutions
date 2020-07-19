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
int E[101];
int S[101];
long long dist[101][101];
double times[101][101];
const long long inf=1e12;


int main(){
    int T;
    cin>>T;
    int N,Q;
    int u,v;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>Q;
        for(int i=0;i<N;++i){cin>>E[i]; cin>>S[i];}
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin>>dist[i][j];
                if(dist[i][j]<0){dist[i][j]=inf;}
            }
        }

        for(int k=0;k<N;++k){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(dist[i][j]!=inf && dist[i][j]<=E[i]){
                    times[i][j]=((double)dist[i][j])/S[i];
                }
                else{times[i][j]=inf;}
            }
        }

        for(int k=0;k<N;++k){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    times[i][j]=min(times[i][j],times[i][k]+times[k][j]);
                }
            }
        }
        cout.precision(6);
        cout<<"Case #"<<tt<<":";
        for(int i=0;i<Q;++i){
            cin>>u>>v;
            cout<<" "<<fixed<<times[u-1][v-1];
        }
        cout<<endl;
    }
}
