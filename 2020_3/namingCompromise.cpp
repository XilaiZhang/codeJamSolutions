#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;
int dp[61][61];
int parent[61][61];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        string end;
        string start;
        cin>>end>>start;
        //cout<<"end is "<<end<<" start is "<<start<<endl;
        int m=end.size();
        int n=start.size();
        for(int i=0;i<=m;++i){
            dp[i][0]=i;
            parent[i][0]=-1;
        }
        for(int i=1;i<=n;++i){
            dp[0][i]=i;
            parent[0][i]=-1;
        }
        for(int i=1;i<=m;++i){ //let's assume delete==insert
            for(int j=1;j<=n;++j){
                if(end[i-1]==start[j-1]){dp[i][j]=dp[i-1][j-1];parent[i][j]=0;}
                else{dp[i][j]=1+dp[i-1][j-1];parent[i][j]=1;}
                if(dp[i-1][j]+1<dp[i][j]){
                    dp[i][j]=dp[i-1][j]+1;
                    parent[i][j]=2; // from start insert 1
                }
                if(dp[i][j-1]+1<dp[i][j]){
                    dp[i][j]=dp[i][j-1]+1;
                    parent[i][j]=3; // from start delete 1
                }
            }
        }

        int seq=0;
        int target=dp[m][n]/2;
        vector<char>st;

        int posE=m;
        int posS=n;
        while(seq!=target){
            if(parent[posE][posS]==0){st.push_back(start[posS-1]);posE-=1;posS-=1;}
            else if(parent[posE][posS]==1){st.push_back(end[posE-1]);posE-=1;posS-=1;seq++;}
            else if(parent[posE][posS]==2){st.push_back(end[posE-1]);posE-=1;seq++;}
            else if(parent[posE][posS]==3){posS-=1;seq++;}
            else{//parent is -1
                if(posE>0){st.push_back(end[posE-1]);posE--;}
                else{posS-=1;}
                seq++;
            }
        }

        string result=start.substr(0,posS);
        while(!st.empty()){
            result+=st.back();
            st.pop_back();
        }


        cout<<"Case #"<<tt<<": "<<result<<endl;   
        
        
    }  
}
