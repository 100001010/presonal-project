#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int c(string s){
    int r=0;
    for(int i=0;i<s.size();i++)
        r+=(s[s.size()-i-1]-'0')*pow(2,i);
    return r;
}
int coprime(int a,int b){
    while(!(a==0||b==0)){
        a=a%b;
        swap(a,b);
    }
    if(max(a,b)!=1)
        return 0;
    else
        return 1;
}
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s1,s2;
    int kase;cin>>kase;
    for(int i=1;cin>>s1>>s2&&i<=kase;i++){
        int i1=c(s1),i2=c(s2);
        if(coprime(i1,i2))
            printf("Pair #%d: Love is not all you need!\n",i);
        else
             printf("Pair #%d: All you need is love!\n",i);
    }
}