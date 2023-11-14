#include<iostream>
#include<string>
using namespace std;
int main(){
    int ans[128]={};
    int n;cin>>n;
    string s;getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        for(char c:s)
            ans[toupper(c)]++;
    }
    for(int j=1000;j>0;j--)
        for(int i=65;i<=90;i++){
            if(ans[i]==j){
                cout<<char(i)<<" "<<ans[i]<<endl;
            }
        }
}
