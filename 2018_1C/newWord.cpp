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

string compute(string answer, int startIndex, unordered_map<int,unordered_set<char>> & charDict,
        unordered_set<string> & seen, int L){
    if(startIndex==L){
        if(seen.find(answer)==seen.end()){return answer;}
        else{return "";}
    }

    for(char x:charDict[startIndex]){
        string possible=compute(answer+string(1,x),startIndex+1,charDict,seen, L);
        if(possible!=""){return possible;}
    }
    return "";
}

int main(){
    int T;
    cin>>T;
    string word;
    
    for(int tt=1;tt<T+1;++tt){
        int N,L;
        cin>>N>>L;
        unordered_map<int,unordered_set<char>> charDict;
        unordered_set<string>seen;
        for(int i=0;i<N;++i){
            cin>>word;
            seen.insert(word);
            for(int j=0;j<L;++j){
                charDict[j].insert(word[j]);
            }
        }

        string result="";
        result=compute("",0,charDict,seen,L);
        if(result==""){cout<<"Case #"<<tt<<": -"<<endl;}
        else{cout<<"Case #"<<tt<<": "<<result<<endl;}

    }
}
