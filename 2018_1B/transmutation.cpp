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
long long upperBound;
long long lowerBound;

long long add(long long a, long long b){
    if(a+b>=0){return min(upperBound,a+b);}
    else{return max(lowerBound,a+b);}
}

long long mult(long long a, long long b){
    if(a==0){return 0;}
    if(upperBound/a < b){return upperBound;}
    return a*b;
}

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        int M;
        cin>>M;
        vector<vector<long long>> formula(M+1,vector<long long>(M+1,0));
        for(int i=1;i<=M;++i){
            int R1,R2;
            cin>>R1>>R2;
            formula[i][R1]=1;
            formula[i][R2]=1;
        }

        vector<long long> numbers(M+1);
        long long high=0;
        for(int i=1;i<=M;++i){
            cin>>numbers[i];
            high+=numbers[i];
        }

        lowerBound=-high-10;
        upperBound=high+10;

        long long low=0;
        while(low<high){
            long long mid=low+(high-low)/2;
            vector<long long> nums=numbers;
            vector<vector<long long>>recipe=formula;
            nums[1]-=mid;
            bool possible=true;
            bool done=false;
            while(!done){
                done=true;
                for(int j=1;j<=M;++j){
                    if(nums[j]<0){
                        done=false;
                        if(recipe[j][j]>0 || nums[j]<=lowerBound){possible=false;break;}
                        for(int k=1;k<=M;++k){
                            if(recipe[j][k]>=upperBound){possible=false;break;} //later
                            if(recipe[j][k]>0){nums[k]=add(nums[k],-mult(-nums[j],recipe[j][k]));}
                        }
                        for(int other=1;other<=M;++other){
                            if(recipe[other][j]>0){
                                long long amount=recipe[other][j];
                                recipe[other][j]=0;
                                for(int rep=1;rep<=M;++rep){
                                    if(recipe[j][rep]>0){recipe[other][rep]=add(recipe[other][rep],
                                        mult(amount, recipe[j][rep]));}
                                }
                            }
                        }
                        nums[j]=0;
                        break;
                    }
                }
                if(!possible){break;}
                if(done){possible=true;break;}
            }
            //cout<<"when low is "<<low<<" and high is "<<high<<" and mid is "<<mid<<" possible is "<<possible<<endl;
            if(possible){low=mid+1;}
            else{high=mid;}
        }

        cout<<"Case #"<<tt<<": "<<low-1<<endl; 

    }
}
