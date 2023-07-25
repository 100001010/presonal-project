#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(cin>>n){
        int b1=0,b2=0;
        int t=n;
        while(t>0){
            b1+=t%2;
            t/=2;
        }
        t=n;
        while(t>0){
            int digit1=t%10;
            while(digit1>0){
                b2+=digit1%2;
                digit1/=2;
            }
            t/=10;
        }
        cout<<b1<<" "<<b2<<endl;
    }
}