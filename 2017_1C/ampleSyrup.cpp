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
double dp[1001];

bool sorty(const pair<int,int> &a, const pair <int,int> &b){return a.first>b.first;}


int main(){
    int T;
    cin>>T;
    int N,K;
    double R,H;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>K;
        vector<pair<double,double>> p;
        for(int i=0;i<N;++i){
            cin>>R>>H;
            p.push_back({R,H});
        }
        sort(p.begin(),p.end(),sorty);

        memset(dp,0,sizeof dp);
    
        for(int i=0;i<N;++i){
            double base=M_PI*(p[i].first)*(p[i].first);
            double increment=2*M_PI*(p[i].first)*(p[i].second);
            for(int j=K;j>1;j--){
                if(dp[j-1]!=0){dp[j]=max(dp[j],dp[j-1]+increment);}
            }
            dp[1]=max(dp[1],base+increment);
        }

        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<dp[K]<<endl;

    }
}
