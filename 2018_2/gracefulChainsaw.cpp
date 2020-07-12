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

int main(){
    int T;
    cin>>T;
    vector<vector<int>>dp(501, vector<int>(501, -100));
    dp[0][0]=0;
    for(int x=0;x<=50;++x){
        for(int y=0;y<=50;++y){
            if(x==0 && y==0){continue;}

            for(int r=500;r>=x;r--){
                for(int b=500;b>=y;b--){
                    if(dp[r-x][b-y]>=0){dp[r][b]=max(dp[r][b],dp[r-x][b-y]+1);}
                }
            }
        }
    }


    for(int tt=1;tt<T+1;++tt){
        int R,B;
        cin>>R>>B;
        
        cout<<"Case #"<<tt<<": "<<dp[R][B]<<endl;

    }
}
