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

using namespace std; //might have problem with loop detection
int R,C;
char grid[51][51];
//let 0 right 1 down 2 left 3 up
int dir1[4]={0,1,0,-1};
int dir2[4]={1,0,-1,0};
int a[4]={3,2,1,0}; //if hits a /
int b[4]={1,0,3,2}; // if hits a \

vector<int> horiCells; //might have repeats, but i don't think it matters
vector<int> vertiCells;

vector<int> enforced;
vector<unordered_set<int>> lasers;
vector<vector<int>> coveredCells;

unordered_set<int> nodes;
unordered_map<int, unordered_set<int>>graph;

unordered_map<int,int> discover;
unordered_map<int,int> low;
vector<int> pointStack;
unordered_set<int> inStack;

int seq;
int sccSeq;

unordered_map<int,int> sccNumber;
unordered_map<int, unordered_set<int>> parent;
unordered_map<int, unordered_set<int>> children;
unordered_map<int,vector<int>> sccGroup;

void init(){
    vector<int> v1(R*C+1,0);
    enforced=v1;
    vector<unordered_set<int>> v2(R*C+1);
    lasers=v2;
    vector<vector<int>> v5(2*R*C+3);
    coveredCells=v5;
    nodes.clear();

    unordered_map<int, unordered_set<int>>v3;
    graph=v3;
    discover.clear();
    low.clear();
    pointStack.clear();
    seq=1;
    sccSeq=1;
    sccNumber.clear();
    parent.clear();
    children.clear();
    sccGroup.clear();
}

void findScc(int u){
    pointStack.push_back(u);
    inStack.insert(u);
    discover[u]=seq;
    low[u]=seq;
    seq++;
    for(int neighbor:graph[u]){
        if(discover.find(neighbor)==discover.end()){
            findScc(neighbor);
            low[u]=min(low[u],low[neighbor]);
        }
        else if(inStack.find(neighbor)!=inStack.end()){
            low[u]=min(low[u],discover[neighbor]);
        }
    }
    int w=-1;
    if(low[u]==discover[u]){
        while(w!=u){
            w=pointStack.back();
            pointStack.pop_back();
            sccNumber[w]=sccSeq;
            inStack.erase(w);
            sccGroup[sccSeq].push_back(w);
        }
        sccSeq++;
    }
}

int search(int direction, int x, int y, int horizontal){
    //cout<<"direction is "<<direction<<" x and y are "<<x<<" "<<y<<"  R and C are "<<R<<" "<<C<<endl;
    if(x<0 || x>=R || y<0 || y>=C || grid[x][y]=='#'){return 0;}
    if(grid[x][y]=='-' || grid[x][y]=='|'){return -1;}
    else if(grid[x][y]=='/'){return search(a[direction],x+dir1[a[direction]],y+dir2[a[direction]], horizontal);}
    else if(grid[x][y]=='\\'){return search(b[direction],x+dir1[b[direction]],y+dir2[b[direction]], horizontal);}
    else if(grid[x][y]=='.'){
        if(horizontal){horiCells.push_back(x*C+y);}
        else{vertiCells.push_back(x*C+y);}
        return search(direction,x+dir1[direction],y+dir2[direction],horizontal);
    }
    else{assert(1==0);return 3;}
}

int solve(){
    string line;
    int x1,x2,y1,y2;
    bool hori,verti;

    cin>>R>>C;
    init();
    for(int i=0;i<R;++i){
        cin>>line;
        for(int j=0;j<C;++j){
            grid[i][j]=line[j];
        }
    }
    
    init();
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(grid[i][j]=='|' || grid[i][j]=='-'){
                //cout<<"now looking at "<<i<<" "<<j<<endl;
                horiCells.clear();
                vertiCells.clear();
                x1=search(0,i,j+1,1);
                x2=search(2,i,j-1,1);
                if(x1<0 || x2<0){hori=false;}
                else{hori=true;}
                y1=search(1,i+1,j,0);
                y2=search(3,i-1,j,0);
                if(y1<0 || y2<0){verti=false;}
                else{verti=true;}

                int l=i*C+j;//the seq number of laser
                if(!hori && !verti){return -1;}
                else if(hori && !verti){
                    for(int point: horiCells){
                        lasers[point].insert(l<<1); //a horizontal passing laser
                        coveredCells[l<<1].push_back(point);
                    }
                    enforced[l]=1;
                }
                else if(verti && !hori){
                    for(int point: vertiCells){
                        lasers[point].insert((l<<1)+1); // a vertical passing laser
                        coveredCells[(l<<1)+1].push_back(point);
                    }
                    enforced[l]=2;
                }
                else{ //both hori and verti are possible
                    for(int point: horiCells){
                        lasers[point].insert(l<<1);
                        coveredCells[l<<1].push_back(point);
                    }
                    for(int point: vertiCells){
                        lasers[point].insert((l<<1)+1);
                        coveredCells[(l<<1)+1].push_back(point);
                    } 
                }
            }  
        }
    }

    unordered_set<int>seen;
    vector<int> oneGroup;

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(grid[i][j]=='.'){
                int myNode=i*C+j;
                if(lasers[myNode].empty()){return -1;}
                else if(lasers[myNode].size()==1){
                    oneGroup.push_back(myNode);
                }
            }
        }
    }

    while(!oneGroup.empty()){
        int myNode=oneGroup.back();
        oneGroup.pop_back();
        if(seen.find(myNode)!=seen.end()){continue;}
        seen.insert(myNode);
        int l= * (lasers[myNode].begin());
        int expect=(l & 1)+1; //expect the only laser to be in this direction
        if(!enforced[(l>>1)]){
            enforced[l>>1]=expect;
            int opposite=(l^1);
            for(int af:coveredCells[opposite]){
                lasers[af].erase(opposite);
                if(lasers[af].empty()){return -1;}
                else if(lasers[af].size()==1){oneGroup.push_back(af);}
            }
        }
        else if(enforced[l>>1] && enforced[l>>1]!=expect){return -1;}
        else{continue;}
    }
    

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(grid[i][j]=='.'){
                int myNode=i*C+j;
                if(lasers[myNode].size()==2){
                    vector<int> twoNode;
                    for(int possible: lasers[myNode]){
                        twoNode.push_back(possible);
                    }
                    twoNode.push_back(twoNode[0]^1);
                    twoNode.push_back(twoNode[1]^1);
                    for(int some:twoNode){nodes.insert(some);}
                    graph[twoNode[2]].insert(twoNode[1]);
                    graph[twoNode[3]].insert(twoNode[0]);
                }
            }
        }
    }

    for(int x:nodes){
        if(discover.find(x)==discover.end()){
            findScc(x);
        }
    }

    for(int x:nodes){
        if(sccNumber[x]==sccNumber[x^1]){return -1;}
    }

    for(int u:nodes){
        for(int v:graph[u]){
            if(sccNumber[u]!=sccNumber[v]){
                parent[sccNumber[v]].insert(sccNumber[u]);
                children[sccNumber[u]].insert(sccNumber[v]);
            }
        }
    }

    vector<int> zs;
    for(int i=1;i<sccSeq;i++){if(parent.find(i)==parent.end()){zs.push_back(i);}}
    while(!zs.empty()){
        int number=zs.back();
        zs.pop_back();
        for(int p:sccGroup[number]){
            if(!enforced[(p>>1)]){
                if(p&1){enforced[p>>1]=1;} //if vertical, assign false, so enforced horizontal
                else{enforced[p>>1]=2;}
            }
        }
        for(int child:children[number]){
            parent[child].erase(number);
            if(parent[child].empty()){zs.push_back(child);}
        }

    }

    return 0;
}

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        int res=solve();
        if(res<0){cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;continue;}
        cout<<"Case #"<<tt<<": "<<"POSSIBLE"<<endl;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                if(grid[i][j]=='-' || grid[i][j]=='|'){
                    if(enforced[i*C+j]==1){cout<<"-";}
                    else{cout<<"|";}
                }
                else{cout<<grid[i][j];}
            }
            cout<<endl;
        }

    }
}
