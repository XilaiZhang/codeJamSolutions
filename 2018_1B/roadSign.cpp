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
int leftPos [100000];
int rightPos [100000];

int result=0;
int quantity=0;

void evaluate(vector<pair<int,int>> & possible){
    unordered_map<int,unordered_set<int>>  seen;
    for(int i=0;i<possible.size();++i){
        int a=possible[i].first;
        int b=possible[i].second;
        if(seen[a].find(b)!=seen[a].end()){continue;}
        if(b-a-1>result){result=b-a-1;quantity=1;}
        else if(b-a-1==result){quantity++;}
        seen[a].insert(b);
    }
}

pair<int,int> seq(int start, int end, int leftVal, int rightVal, int point){
    int r=point+1;
    while(r<=end && (leftPos[r]==leftVal || rightPos[r]==rightVal)){r++;}
    int l=point-1;
    while(l>=start && (leftPos[l]==leftVal || rightPos[l]==rightVal)){l--;}
    return make_pair(l,r);
}

void compute(int start, int end){
    if(end-start+1<result){return;}
    if(start==end){if(result<1){result=1;quantity=1;}
        else if(result==1){quantity++;}
        return;
    }
    else if(start>end){return;}
    int mid=(start+end)/2;
    int r1=mid-1;
    int r2=mid+1;
    vector<pair<int,int>> possible;
    while(r2<=end && rightPos[r2]==rightPos[mid]){r2++;}
    while(r1>=start && rightPos[r1]==rightPos[mid]){r1--;}
    if(r2<=end){
        possible.push_back(seq(start,end,leftPos[r2],rightPos[mid],mid));
    }
    if(r1>=start){
        possible.push_back(seq(start,end,leftPos[r1],rightPos[mid],mid));
    }

    int l1=mid-1;
    int l2=mid+1;
    while(l2<=end && leftPos[l2]==leftPos[mid]){l2++;}
    while(l1>=start && leftPos[l1]==leftPos[mid]){l1--;}
    if(l2<=end){
        possible.push_back(seq(start,end,leftPos[mid],rightPos[l2],mid));
    }
    if(l1>=start){
        possible.push_back(seq(start,end,leftPos[mid],rightPos[l1],mid));
    }
    evaluate(possible);

    compute(start,mid-1);
    compute(mid+1,end);
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        result=0;
        quantity=0;
        int S;
        cin>>S;
        int D,A,B;
        for(int i=0;i<S;++i){
            cin>>D>>A>>B;
            leftPos[i]=D-B;
            rightPos[i]=D+A;
        }
        compute(0,S-1);
        cout<<"Case #"<<tt<<": "<<result<<" "<<quantity<<endl; 

    }
}
