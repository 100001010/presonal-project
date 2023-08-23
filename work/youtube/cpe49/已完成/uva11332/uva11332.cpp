#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n,n!=0){
        while(n>=10){
            int t=0;
            while(n>0){
                t+=n%10;
                n/=10;
            }
            n=t;
        }
        cout<<n<<endl;;;;;;
    }
}