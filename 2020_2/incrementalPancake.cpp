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
const long long bound1=1.42e9;

int main(){
    int T;
    cin>>T;
    for(int tt=1;tt<T+1;++tt){
        long long L,R;
        cin>>L>>R;
        long long diff=L-R;
        long long low=1;
        long long high=1e18+1;
        long long result=0;

        if(L>=R){
            while(low<high){
                long long mid=low+(high-low)/2;
                long long sum=(1+mid)*mid/2;
                if(mid>bound1 || sum>diff){high=mid;}
                else{low=mid+1;}
            }
            L=L-(1+low-1)*(low-1)/2; //try low-1 first
            result+=low-1;
            if(L>=low){
                L-=low;
                result++;
            }else{
                cout<<"Case #"<<tt<<": "<<result<<" "<<L<<" "<<R<<endl;  
                continue;  //return directly
            }

            //low+1,low+3, ...
            long long r1=1;
            long long r2=(1e18+1-low)/2;
            r2++;
            while(r1<r2){
                long long r3=r1+(r2-r1)/2;
                long long s=(1+r3)*r3-r3+low*r3;
                if(r3>1e18/double(low) || r3>sqrt(1e18-low*r3) || s>R){r2=r3;}
                else{r1=r3+1;}
            }
            //r1-1 is the max

            long long l1=1;
            long long l2=(1e18-low)/2;
            l2++;
            while(l1<l2){
                long long l3=l1+(l2-l1)/2;
                long long s=(1+l3)*l3+low*l3;
                if(l3>1e18/double(low) || l3>sqrt(1e18-low*l3) || s>L){l2=l3;}
                else{l1=l3+1;}
            }
            //l1-1 is the max

            if(r1<=l1) //r1-1 is the bound
            {
                result+=2*(r1-1);
                R-=2*(1+r1-1)*(r1-1)/2-r1+1+low*(r1-1);
                L-=2*(1+r1-1)*(r1-1)/2+low*(r1-1);
            }
            else{ //l1-1 and l1 are the bound
                result+=l1-1+l1;
                R-=2*(1+l1)*l1/2-l1+low*l1;
                L-=2*(1+l1-1)*(l1-1)/2+low*(l1-1);
            }
        }
        else{
            diff=R-L;
            while(low<high){
                long long mid=low+(high-low)/2;
                long long sum=(1+mid)*mid/2;
                if(mid>bound1 || sum>=diff){high=mid;}
                else{low=mid+1;}
            }

            R=R-(1+low-1)*(low-1)/2;
            result+=low-1;

            if(R>=low){
                R-=low;
                result++;
            }else{
                cout<<"Case #"<<tt<<": "<<result<<" "<<L<<" "<<R<<endl;  
                continue;  //return directly
            }

            //low+1,low+3, ...
            long long l1=1;
            long long l2=(1e18+1-low)/2;
            l2++;
            while(l1<l2){
                long long l3=l1+(l2-l1)/2;
                long long s=2*(1+l3)*l3/2-l3+low*l3;
                if(l3>1e18/double(low) || l3>sqrt(1e18-low*l3) || s>L){l2=l3;}
                else{l1=l3+1;}
            }
            //l1-1 is the max

            long long r1=1;
            long long r2=(1e18-low)/2;
            r2++;
            while(r1<r2){
                long long r3=r1+(r2-r1)/2;
                long long s=(1+r3)*r3+low*r3;
                if(r3>1e18/double(low) || r3>sqrt(1e18-r3*low) || s>R){r2=r3;}
                else{r1=r3+1;}
            }
            //r1-1 is the max

            if(l1<=r1) //l1-1 is the bound
            {
                result+=2*(l1-1);
                L-=2*(1+l1-1)*(l1-1)/2-l1+1+low*(l1-1); //the last one could be very large
                R-=2*(1+l1-1)*(l1-1)/2+low*(l1-1);
            }
            else{ //r1-1 and r1 are the bound
                result+=r1-1+r1;
                L-=2*(1+r1)*r1/2-r1+low*r1;
                R-=2*(1+r1-1)*(r1-1)/2+low*(r1-1);
            }

        }

        
        
        cout<<"Case #"<<tt<<": "<<result<<" "<<L<<" "<<R<<endl;   
    }  
}
