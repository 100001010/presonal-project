#include<iostream>
#include<vector>
#include<string>
using namespace std;
int point=-1;
int f(string s,int n){
    point++;
    if(s[point]=='0'){
        return 0; 
    }else if(s[point]=='1'){
        return n*n;
    }else{
        return f(s,n/2)+f(s,n/2)+f(s,n/2)+f(s,n/2);
    }
}

int main(){
    // #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    // #endif
    string s;
    int n;
    cin>>s>>n;
    cout<<f(s,n);
}