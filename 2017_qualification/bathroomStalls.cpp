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
        long long N,K;
        cin>>N>>K;
        unordered_map<long long, long long> times;
        priority_queue<long long> q;
        q.push(N);
        times[N]++;
        long long current=0;
        long long a,b;

        while(current<K){
            long long number=q.top();
            q.pop();
            current+=times[number];
            a=(number>>1);
            b=(number>>1);
            if ( !(number & 1)){b--;}
            
            if(times.find(a)==times.end()){q.push(a);}
            times[a]+=times[number];

            if(times.find(b)==times.end()){q.push(b);}
            times[b]+=times[number];

        }
        
        cout<<"Case #"<<tt<<": "<<a<<" "<<b<<endl;

    }
}
