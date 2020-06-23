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
int N;
int parent[100];
int groupSize[100];

int gcd(int a, int b){
    if(b==0){return a;}
    else{return gcd(b,a%b);}
}

int find(int p, unordered_set<int> & seen){
    if(seen.find(p)==seen.end()){
        seen.insert(p);
        parent[p]=p;
        groupSize[p]=1;
        return p;
    }
    int it=p;
    while(parent[it]!=it){
        it=parent[it];
    }
    parent[p]=it;
    return it;
}

void un(int a, int b, unordered_set<int> & seen){
    int p1=find(a,seen);
    int p2=find(b,seen);
    if(p1!=p2){
        parent[p1]=p2;
        groupSize[p2]+=groupSize[p1];
    }
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        unordered_map<int, unordered_map<int, vector<pair<int,int>> >> edgePairs;
        vector<pair<int,int>>points;
        for(int i=0;i<N;++i){
            int x,y;
            cin>>x>>y;
            points.push_back({x,y});
        }

        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                int y1=points[i].second-points[j].second;
                int x1=points[i].first-points[j].first;
                if(x1!=0 && y1!=0){
                    int k=gcd(abs(y1),abs(x1));
                    y1/=k;
                    x1/=k;
                }
                else if(x1==0){
                    y1=1;
                }
                else{//y1==0
                    x1=1; 
                } 
                if((y1<0 && x1<0) || (y1<0 && x1>0)){y1=-y1;x1=-x1;}

                edgePairs[y1][x1].push_back({i,j});
            }
        }

        if(N==1){
            cout<<"Case #"<<tt<<": "<<1<<endl;
            continue; 
        }

        int result=0;
        for(auto it1:edgePairs){
            for(auto it2:it1.second){
                unordered_set<int> seen;

                for(int i=0;i<it2.second.size();++i){
                    int a=it2.second[i].first;
                    int b=it2.second[i].second;
                    un(a,b,seen);
                }
                int oddGroup=0;
                for(int s:seen){
                    if(parent[s]==s && (groupSize[s]%2==1)){
                        oddGroup++;
                    }
                }
                if(oddGroup%2==0){
                    result=max(result, (int)seen.size()+min(2,N-(int)seen.size()) );
                }
                else{
                    result=max(result, (int)seen.size()+min(1,N-(int)seen.size()) );
                }
            }
        }   

        cout<<"Case #"<<tt<<": "<<result<<endl;   
    }  
}
