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
int W[100000];
long long dp[140];
long long bound=1e15;

int main(){
    int T;
    cin>>T;
    
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>W[i];
        }

        for(int j=0;j<140;++j){
            dp[j]=bound;
        }

        dp[0]=0;
        dp[1]=W[0];
        
        for(int i=1;i<N;++i){
            for(int j=139;j>0;--j){
                if(dp[j-1]<=(long long)6*W[i]){dp[j]=min(dp[j],dp[j-1]+W[i]);}
            }
        }
        int result=0;
        while(result<140 && dp[result]<bound){result++;}
        cout<<"Case #"<<tt<<": "<<result-1<<endl;

    }
}
