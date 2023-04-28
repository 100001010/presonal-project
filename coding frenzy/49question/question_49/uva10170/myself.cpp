#include<iostream>
using namespace std;
int main(){
    long long int a,b;
    while(cin>>a>>b){
        long long int t;
        for(a;t<b;a++){
            t+=a;
        }
        cout<<--a<<endl;
    }
    return 0;
    
}