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

long long gcd(long long a, long long b){
    if(b==0){return a;}
    else{return gcd(b,a%b);}
}

struct frac{
    long long numerator;
    long long denominator;
    long long fully;
    frac(long long a,long long b, long long f){
        numerator=a;
        denominator=b;
        fully=f;
    }
    bool operator < (const frac & other) const{
        return numerator*(other.denominator) < denominator*(other.numerator); 
    }
};

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N,D;
        cin>>N>>D;
        vector<long long > numbers(N);
        long long maxA=0;
        for(int i=0;i<N;++i){
            cin>>numbers[i];
            maxA=max(maxA,numbers[i]);
        }
        sort(numbers.begin(),numbers.end());

        int maxM=1;
        unordered_map<long long, unordered_map<long long, int>> fully;
        unordered_map<long long, unordered_map<long long, int>> slices;
        for(int i=0;i<N;++i){
            
            for(long long j=1;j<=D;++j){ 
                long long g=gcd(numbers[i],j);
                long long a=numbers[i]/g;
                long long b=j/g;
                
                if(slices[a][b]+j<=D){
                    fully[a][b]++;
                    slices[a][b]+=j;
                }
                
            }
        }
        vector<frac> fractions;
        for(auto it1:fully){
            for(auto it2: it1.second){
                frac frac1(it1.first, it2.first, it2.second);
                fractions.push_back(frac1);
            }
        }
        sort(fractions.begin(),fractions.end());
        int low=0;
        int high=fractions.size();
        while(low<high){
            int mid=(low+high)/2;
            long long a=fractions[mid].numerator;
            long long b=fractions[mid].denominator;
            long long count=0;
            for(int k=0;k<N;++k){
                count+=numbers[k]*b/a;
            }
            if(count<D){high=mid;}
            else{low=mid+1;}
        }
        int pos=low-1;
        for(int i=0;i<=pos;++i){
            frac f1=fractions[i];
            maxM=max(fully[f1.numerator][f1.denominator],maxM);
        }
        cout<<"Case #"<<tt<<": "<<D-maxM<<endl;   
    }  
}
