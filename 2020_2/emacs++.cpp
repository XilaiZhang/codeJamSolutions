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
int S[100001];
int E[100001];
int parent[100001];
int children[100001];
int position[100001];
int match[100001];
string word;

vector<int> find(int it, int leftPos, int rightPos, int leftCost, int rightCost){
    while(parent[leftPos]!=it){

        leftCost=leftCost+position[leftPos];
        leftPos=parent[leftPos];
   
        rightCost=rightCost+children[parent[rightPos]]-position[rightPos]+1;
        rightPos=match[parent[rightPos]];
        
        int minLeft=min(leftCost,rightCost+1);
        int minRight=min(leftCost+1,rightCost);

        leftCost=minLeft;
        rightCost=minRight;
    }
    
    return {leftPos,rightPos,leftCost,rightCost};
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int K,Q;
        cin>>K>>Q;
        cin>>word;
        for(int i=0;i<3*K;++i){
            int Li;
            cin>>Li;
        }
        for(int i=1;i<=Q;++i){
            cin>>S[i];
        }
        for(int i=1;i<=Q;++i){
            cin>>E[i];
        }
        memset(children,0,sizeof children);
        vector<int> prev={0}; //parent could be 0
        for(int i=0;i<K;++i){
            if(word[i]==')'){
                match[i+1]=prev.back();
                match[prev.back()]=i+1;
                prev.pop_back();
            }
            parent[i+1]=prev.back();
            children[prev.back()]++;
            position[i+1]=children[prev.back()];

            if(word[i]=='('){
                prev.push_back(i+1);
            }
        }
        long long result=0;

        for(int i=1;i<=Q;++i){
            int it1=S[i];
            int it2=E[i];
            while(parent[it1]!=parent[it2]){
                if(parent[it1]<parent[it2]){it2=parent[it2];}
                else{ //it1>it2
                    it1=parent[it1];
                }
            }
            int it=parent[it1];

            vector<int>v1;
            if(word[S[i]-1]=='('){
                v1=find(it,S[i],match[S[i]],0,1);
            }
            else if(word[S[i]-1]==')'){
                v1=find(it,match[S[i]],S[i],1,0);
            }
            else{
                v1=find(it,S[i],S[i],0,0);
            }

            vector<int>v2;
            if(word[E[i]-1]=='('){
                v2=find(it,E[i],match[E[i]],0,1);
            }
            else if(word[E[i]-1]==')'){
                v2=find(it,match[E[i]],E[i],1,0);
            }
            else{
                v2=find(it,E[i],E[i],0,0);
            }

            int answer=100001;
            if(v1[0]==v2[0]){
                answer=min(min(answer,v1[2]+v2[2]),v1[3]+v2[3]);
                result+=answer;
                continue;
            }
            if(v1[0]>v2[0]){
                vector<int>tmp=v1;
                v1=v2;
                v2=tmp;
            }
            
            if(it!=0){
                vector<int>v3=find(parent[it],v1[0],v1[1],v1[2],v1[3]);
                vector<int>v4=find(parent[it],v2[0],v2[1],v2[2],v2[3]);
                answer=min(answer,v3[2]+v4[3]+1);
            }

            int middle=position[v2[0]]-position[v1[1]];
            answer=min(answer,middle+v1[3]+v2[2]);
            result+=answer;
        }

        cout<<"Case #"<<tt<<": "<<result<<endl;   
        
        
    }  
}
