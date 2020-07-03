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
#include <assert.h>

using namespace std;
int prefixRow[16][16];
int prefixCol[16][16];
int state[15][15][15][15];

int solve(int x1,int x2, int y1, int y2){
    if(x1>x2 || y1>y2){return 0;}
    if(state[x1][x2][y1][y2]!=-1){return state[x1][x2][y1][y2];}
    set <int> seen;
    for(int h=x1;h<=x2;++h){
        int hazard=prefixRow[h+1][y2+1];
        if(hazard>=y1){continue;}

        int up=solve(x1,h-1,y1,y2);
        int down=solve(h+1,x2,y1,y2);
        seen.insert(up ^ down);
    }

    for(int v=y1;v<=y2;++v){
        int hazard=prefixCol[x2+1][v+1];
        if(hazard>=x1){continue;}
        
        int left=solve(x1,x2,y1,v-1);
        int right=solve(x1,x2,v+1,y2);
        seen.insert(left ^ right);
    }

    int p=0;
    while(seen.find(p)!=seen.end()){p++;}
    state[x1][x2][y1][y2]=p;
    return p;

}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<16;++i){prefixRow[i][0]=-1;}
    for(int i=0;i<16;++i){prefixCol[0][i]=-1;}   
    for(int tt=1;tt<T+1;++tt){
        int R,C;
        cin>>R>>C;
        for(int i=0;i<R;++i){
            string line;
            cin>>line;
            for(int j=0;j<C;++j){
                char letter=line[j];
                if(letter=='#'){
                    prefixRow[i+1][j+1]=j;
                    prefixCol[i+1][j+1]=i;
                }
                else{
                    prefixRow[i+1][j+1]=prefixRow[i+1][j];
                    prefixCol[i+1][j+1]=prefixCol[i][j+1];
                }
            }
        }
        
        for(int x1=0;x1<R;++x1){
            for(int x2=0;x2<R;++x2){
                for(int y1=0;y1<C;++y1){
                    for(int y2=0;y2<C;++y2){
                        state[x1][x2][y1][y2]=-1; 
                    }
                }
            }
        }
        int result=solve(0,R-1,0,C-1);
        
        int ways=0;
        if(result!=0){
            for(int h=0;h<R;++h){
                if(prefixRow[h+1][C]>-1){continue;}
                if((solve(0,h-1,0,C-1) ^ solve(h+1,R-1,0,C-1))==0)
                { //first move is fixed
                   ways+=C; // the xor of two second moves should evaluates to 0 
                }
                
            }
            for(int v=0;v<C;++v){
                if(prefixCol[R][v+1]>-1){continue;}
                if((solve(0,R-1,0,v-1) ^ solve(0,R-1,v+1,C-1))==0){
                    ways+=R;
                }
            }
            result=ways;
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;   
        
        
    }  
}
