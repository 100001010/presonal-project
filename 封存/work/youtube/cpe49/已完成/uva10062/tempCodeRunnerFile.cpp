#include<iostream>
#include<string>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    int b=0;
    while(getline(cin,s)){
        if(b++!=0)
            cout<<endl;
        int ans[128]={};
        for(int i:s)
            ans[i]++;
        for(int i=1;i<=1000;i++)
            for(int j=127;j>=0;j--){
                if(ans[j]==i)
                    cout<<j<<" "<<i<<endl;
            }
        
    }
}