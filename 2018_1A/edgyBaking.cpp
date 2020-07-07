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
int W[101];
int H[101];
double D[101];
double base[25001];

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        double P;
        cin>>N>>P;
        int sum=0;
        int baseSum=0;
        for(int i=0;i<N;++i){
            cin>>W[i]>>H[i];
            if(W[i]>H[i]){swap(W[i],H[i]);}
            sum+=2*(W[i]+H[i]);
            baseSum+=W[i];
            D[i]=sqrt((double)W[i]*W[i]+(double)H[i]*H[i]);
        }
        for(int i=0;i<=baseSum;++i){base[i]=-1;}
        base[0]=0;
        int prevBase=0;
        for(int i=0;i<N;++i){
            for(int j=prevBase;j>=0;j--){
                if(base[j]>=0){
                    base[j+W[i]]=max(base[j+W[i]],base[j]+D[i]);
                }
            }
            prevBase+=W[i];
        }
        double answer=sum;
        for(int i=0;i<=baseSum && sum+2*i<=P;++i){
            answer=max(answer, min(P, sum+2*base[i]) );
        }
        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<answer<<endl; 



    }
}
