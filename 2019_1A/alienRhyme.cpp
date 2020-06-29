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

struct node{
    unordered_map<char,node*> children;
    bool end;
    node(){
        end=false;
    }
};


int helper(node * dummy){
    if(dummy->children.empty()){return 1;}
    int currentSum=0;
    for(auto it: dummy->children){
        currentSum+=helper(it.second);
    }
    if(dummy->end){currentSum+=1;}
    if(currentSum>=2){currentSum-=2;}
    return currentSum;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int N;
        cin>>N;
        node dummy=node();
        for(int i=0;i<N;++i){
            string word;
            cin>>word;
            reverse(word.begin(),word.end());
            node* it= & dummy;
            for(char c:word){
                if ((it->children).find(c)==(it->children).end() ){
                    it->children[c]=new node();
                }
                it=it->children[c];
            }
            it->end=true;
        }

        int result=0;
        for(auto it:dummy.children){
            result+=helper(it.second);
        }
        int answer=N-result;
        cout<<"Case #"<<tt<<": "<<answer<<endl;   
        
        
    }  
}
