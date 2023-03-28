#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.text","w",stdout);
    #endif
    int a,b;
    while(cin>>a>>b&&(a!=0||b!=0)){
        int c=0,ans=0;
        while(a!=0||b!=0){
            c=(a%10+b%10+c)/10;
            if(c){
                ans+=1;
            }
            a/=10;
            b/=10;
        }
        if(ans==0)
            cout<<"No carry operation."<<endl;
        else if(ans==1)
            cout<<ans<<" carry operation.\n";
        else
            cout<<ans<<" carry operations.\n";
    }
}