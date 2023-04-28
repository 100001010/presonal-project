//ok
#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a,b;
    while(cin>>a>>b&&(a!=0||b!=0)){
        int t=0,ans=0;
        while(a||b){
            t=(a%10+b%10+t)/10;
            if(t){
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