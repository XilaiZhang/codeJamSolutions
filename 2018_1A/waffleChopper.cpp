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
    for(int tt=1;tt<T+1;++tt){
        int R,C,H,V;
        cin>>R>>C>>H>>V;
        int total=0;
        vector<vector<int>> grid(R,vector<int>(C,0));
        vector<int> lineNumbers;
        for(int i=0;i<R;++i){
            string line;
            cin>>line;
            int lineSum=0;
            for(int j=0;j<C;++j){
                if(line[j]=='@'){
                    grid[i][j]=1;
                    lineSum++;
                    total++;
                }
            }
            lineNumbers.push_back(lineSum);
        }
        double piece=(double)total/((H+1)*(V+1));
        if(piece==0){cout<<"Case #"<<tt<<": POSSIBLE"<<endl; continue;}
        if(piece!=floor(piece)){
            cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl; 
            continue;
        }
        int target=total/(H+1);
        int currentSum=0;
        bool p=true;
        vector<int>cut;
        for(int i=0;i<R;++i){
            currentSum+=lineNumbers[i];
            if(currentSum>target){p=false;break;}
            else if(currentSum==target){cut.push_back(i);currentSum=0;}
        }
        if(currentSum!=0 || !p){
            cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl; 
            continue;
        }

        target=piece;
        int start=0;
        vector<pair<int,int>> colCuts(V+1,make_pair(-1,101));
        for(int i=0;i<H+1;++i){
            int bound=cut[i];
            int colSum=0;
            vector<pair<int,int>> intervals;
            for(int j=0;j<C;++j){
                int currentCol=0;
                for(int k=start;k<=bound;++k){currentCol+=grid[k][j];}
                if(currentCol==0 && colSum==piece){intervals.back().second++;}
                if(currentCol>0){
                    if(colSum==piece){colSum=0;}
                    colSum+=currentCol;
                    if(colSum>piece){p=false;break;}//exit
                    else if(colSum==piece){intervals.push_back({j,j});}
                }
                
            }

            for(int t=0;t<intervals.size();++t){
                if(intervals[t].first>colCuts[t].second || intervals[t].second<colCuts[t].first){
                    p=false;break;
                }
                colCuts[t].first=max(colCuts[t].first, intervals[t].first);
                colCuts[t].second=min(colCuts[t].second,intervals[t].second);
            }
            start=bound+1;
            if(!p){break;}
        }
        if(!p){
           cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl; 
        }
        else{
            cout<<"Case #"<<tt<<": POSSIBLE"<<endl; 
        }


    }
}
