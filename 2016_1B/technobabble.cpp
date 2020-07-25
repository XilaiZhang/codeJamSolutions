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
int N;

unordered_map<string, unordered_set<string>> graph;
unordered_map<string,string> matched;
unordered_set<string> firstNames;
unordered_set<string> lastNames;
unordered_set<string> visited;

void init(){
    unordered_map<string, unordered_set<string>>v1(N);
    graph=v1;
    firstNames.clear();
    lastNames.clear();
    matched.clear();
}

bool compute(string firstName){
    for(string neighbor:graph[firstName]){
        if(visited.find(neighbor)==visited.end()){
            visited.insert(neighbor);
            if(matched.find(neighbor)==matched.end() || compute(matched[neighbor])){
                matched[neighbor]=firstName;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    string a,b;

    for(int tt=1;tt<T+1;++tt){
        cin>>N;
        init();
        for(int i=0;i<N;++i){
            cin>>a>>b;
            graph[a].insert(b);
            firstNames.insert(a);
            lastNames.insert(b);
        }
        int count=0;
        for(string word:firstNames){
            visited.clear();
            if(compute(word)){count++;}
        }
        int otherFirstNames=firstNames.size()-matched.size();
        int otherLastNames=lastNames.size()-matched.size();

        cout<<"Case #"<<tt<<": "<<N-count-otherFirstNames-otherLastNames<<endl;
        
    }
}
