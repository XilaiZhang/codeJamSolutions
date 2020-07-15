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
int R,C;
int h,v;
int color;
int visited[20][20];
int grid[20][20];
bool exist[16];
bool hExist[4];
bool vExist[4];

int expand(int x, int y){
    if(x<0 || x>=R || y<0 || y>=C || visited[x][y]){return 0;}
    visited[x][y]=1;
    bool isBlack= (grid[x][y]==1);
    
    if(y<v && x<h){
        if( isBlack && (!(color & 8)) ){return 0;}
        if( !isBlack && (color &8)){return 0;}
    }
    else if(y>=v && x<h){
        if( isBlack && (!(color & 4)) ){return 0;}
        if( !isBlack && (color &4)){return 0;}
    }
    else if(y<v && x>=h){
        if( isBlack && (!(color & 2)) ){return 0;}
        if( !isBlack && (color & 2)){return 0;}
    }
    else if(y>=v && x>=h){
        if( isBlack && (!(color & 1)) ){return 0;}
        if( !isBlack && (color & 1)){return 0;}
    }
   
    int myVal=0;
    myVal+=expand(x+1,y);
    myVal+=expand(x-1,y);
    myVal+=expand(x,y+1);
    myVal+=expand(x,y-1);
    myVal++;
            
    return myVal;
}

int compute(){

    int answer=0;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(!visited[i][j]){
                int p=expand(i,j);
                answer=max(answer,p);
            }
        }
    }
    return answer;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        cin>>R>>C;
        for(int i=0;i<R;++i){
            string line;
            cin>>line;
            for(int j=0;j<C;++j){
                if(line[j]=='B'){grid[i][j]=1;}
                else{grid[i][j]=0;}
            }
        }
        memset(exist,0,sizeof exist);
        memset(hExist,0,sizeof hExist);
        memset(vExist,0,sizeof vExist);
        int m1,m2,m3,m4;
        for(int i=1;i<R;++i){
            for(int j=1;j<C;++j){
                m1=(grid[i-1][j-1]<<1)+grid[i-1][j];
                m2=(grid[i][j-1]<<1)+grid[i][j];
                hExist[m1]=true;
                hExist[m2]=true;
                exist[(m1<<2)+m2]=true;
                m3=(grid[i-1][j-1]<<1)+grid[i][j-1];
                m4=(grid[i-1][j]<<1)+grid[i][j];
                vExist[m3]=true;
                vExist[m4]=true;   
            }
        }
        for(int j=1;j<C;++j){
            hExist[(grid[0][j-1]<<1)+grid[0][j]]=true;
        }
        for(int i=1;i<R;++i){
            vExist[(grid[i-1][0]<<1)+grid[i][0]]=true;
        }
        int result=0;
        for(int cool=0;cool<(1<<4);cool++){
            color=cool;
            for(int vertical=0;vertical<=C;++vertical){
                for(int horizontal=0;horizontal<=R;++horizontal){
                    v=vertical;
                    h=horizontal;
                    if((0<h) && (h<R) && (0<v) && (v<C) && (!exist[ color ]) ) {continue;}
                    if((0<h) && (h<R) && (v==0) && !vExist[ (((color&4)>>2)<<1) + (color & 1) ] ){continue;}
                    if((0<h) && (h<R) && (v==C) && !vExist[ (((color&8)>>3)<<1)+ ((color & 2)>>1) ] ) {continue;}
                    if((0<v) && (v<C) && (h==0) && !hExist[ (color & 3) ] ) {continue;}
                    if((0<v) && (v<C) && (h==R) && !hExist[ (color>>2) ] ){continue;}
                    memset(visited,0,sizeof visited);
                    int r=compute();
                    result=max(result,r);
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<result<<endl;

    }
}
