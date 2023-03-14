#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,ans=0;cin>>n;
    while(cin>>n){
        if(n%10009==1)
            ans++;
    }
    cout<<ans*ans-1;
}