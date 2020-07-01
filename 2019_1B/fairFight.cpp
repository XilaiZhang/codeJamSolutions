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
int N;
const int col=32-__builtin_clz(100000);
int cDict[100000][col];
int dDict[100000][col];

void build(int myDict[][col]){
    for(int j=1;j<32-__builtin_clz(N);++j){
        int bound=N-(1<<j)+1;
        for(int i=0;i<bound;++i){
            int n1=myDict[i][j-1];
            int n2=myDict[i+(1<<(j-1))][j-1];
            myDict[i][j]=max(n1,n2);
        }
    }   
}

int query(int myDict[][col], int L, int R){
    assert(L<=R);
    int x=32-__builtin_clz(R-L+1)-1;
    return max(myDict[L][x],myDict[R-(1<<x)+1][x]);
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int K;
        cin>>N>>K;
        for(int i=0;i<N;++i){cin>>cDict[i][0];}
        for(int i=0;i<N;++i){cin>>dDict[i][0];}
        build(cDict);
        build(dDict);
        long long currentSum=0;
        int mid,cMax,dMax,low,high;
        int leftBound,rightBound;
        for(int i=0;i<N;++i){
            int myVal=cDict[i][0];
            int myD=dDict[i][0];
            
            leftBound=i+1;
            if(i>0){
                low=0;
                high=i;
                while(low<high){
                    mid=(low+high)/2;
                    cMax=query(cDict,mid,i-1);
                    dMax=query(dDict,mid,i);
                    if(cMax>=myVal || myVal+K<dMax){low=mid+1;}
                    else{high=mid;}
                }
                leftBound=low;
            }
           
            if(myVal+K<myD){leftBound=i+1;}
            else{leftBound=min(leftBound,i);}           

            rightBound=i-1;
            if(i<N-1){
                low=i;
                high=N-1;
                while(low<high){
                    mid=(low+high+1)/2;
                    cMax=query(cDict,i+1,mid);
                    dMax=query(dDict,i,mid);
                    if(cMax>myVal || myVal+K<dMax){
                        high=mid-1;
                    }
                    else{low=mid;}  
                }
                rightBound=low;
            }
  
            if(myVal+K<myD){rightBound=i-1;}
            else{rightBound=max(i,rightBound);}

            long long val1=0;
            if(leftBound<=i && rightBound>=i){
                val1=(long long)(i-leftBound+1)*(long long)(rightBound-i+1);
            }

            leftBound=i+1;
            if(i>0){
                low=0;
                high=i;
                while(low<high){
                    mid=(low+high)/2;
                    cMax=query(cDict,mid,i-1);
                    dMax=query(dDict,mid,i);
                    if(cMax>=myVal || myVal-K<=dMax){low=mid+1;}
                    else{high=mid;}      
                }
                leftBound=low; 
            }
 
            if(myVal-K<=myD){leftBound=i+1;}
            else{leftBound=min(i,leftBound);}

            rightBound=i-1;
            if(i<N-1){
                low=i;
                high=N-1;
                while(low<high){
                    mid=(low+high+1)/2;
                    cMax=query(cDict,i+1,mid);
                    dMax=query(dDict,i,mid);
                    if(cMax>myVal || myVal-K<=dMax){
                        high=mid-1;
                    }
                    else{low=mid;}  
                }
                rightBound=low;
            }
             
            if(myVal-K<=myD){rightBound=i-1;}
            else{rightBound=max(i,rightBound);}

            long long val2=0;
            if(leftBound<=i && rightBound>=i){
                val2=(long long)(i-leftBound+1)*(long long)(rightBound-i+1);
            }

            if(val1>0){val1=val1-val2;}
            currentSum+=val1;
            
        }
        
        cout<<"Case #"<<tt<<": "<<currentSum<<endl;   
        
        
    }  
}
