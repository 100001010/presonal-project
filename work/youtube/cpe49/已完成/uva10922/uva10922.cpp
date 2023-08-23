#include<string>
#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    while(cin>>s,s!="0"){
        cout<<s<<" ";
        int total=0,degree=1;
        for(int i:s)
            total+=i-'0';
        if(total%9!=0){
            cout<<"is not a multiple of 9.\n";
            continue;
        }
        while(total!=9){
            int t=0;
            while (total>0){
                t+=total%10;
                total/=10;                
            }
            total=t;
            degree++;
        }
        cout<<"is a multiple of 9 and has 9-degree "<<degree<<".\n";
    }
}