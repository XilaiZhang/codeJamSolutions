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

using namespace std;
int N,K;

int main(){
    int T;
    cin>>T;

    for(int tt=1;tt<T+1;++tt){
        cin>>N>>K;
        vector<double> numbers(N);
        for(int i=0;i<N;++i){cin>>numbers[i];}
        sort(numbers.begin(),numbers.end());
        double result=0;
        for(int i=0;i<=K;++i){
            vector<double>vals(numbers.begin(),numbers.begin()+i);
            for(int x=N-K+i;x<N;++x){vals.push_back(numbers[x]);}
            int j=0;
            int col=0;
            vector<vector<double>> probs(K/2+1,vector<double>(K,0.0));
            while(j<K){
                if(col==0){probs[1][0]=vals[j];probs[0][0]=1-vals[j];col++;j++;continue;}
                for(int num=0;num<=K/2;++num){
                    if(num==0){probs[0][col]=probs[0][col-1]*(1-vals[j]);continue;}
                    probs[num][col]=vals[j]*probs[num-1][col-1]+probs[num][col-1]*(1-vals[j]);
                }
                j++;
                col++;
            }
            result=max(result,probs[K/2][K-1]);
        }
        cout.precision(6);
        cout<<"Case #"<<tt<<": "<<fixed<<result<<endl;
        
    }
}
