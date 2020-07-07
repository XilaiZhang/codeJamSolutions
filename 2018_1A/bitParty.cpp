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
vector<long long> M(1001,0);
vector<int> S(1001,0);
vector<int> P(1001,0);
vector<long long > numbers(1001,0);

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int R,B,C;
        cin>>R>>B>>C;
        int maxS=0,maxP=0;
        for(int i=0;i<C;++i){
            cin>>M[i]>>S[i]>>P[i];
            maxS=max(maxS,S[i]);
            maxP=max(maxP,P[i]);
        }
        long long low=0;
        long long high=(long long)B * (long long ) maxS + (long long )maxP;
        while (low<high){
            long long mid=low+(high-low)/2;
            for(int i=0;i<C;++i){
                numbers[i]=max((long long) 0, min((mid-P[i])/S[i], M[i]) );
            }
            sort(numbers.begin(),numbers.begin()+C,greater<long long>());
            long long available=0;
            for(int i=0;i<R;++i){available+=numbers[i];}
            if(available>=B){high=mid;}
            else{low=mid+1;}
        }
        cout<<"Case #"<<tt<<": "<<low<<endl; 



    }
}
