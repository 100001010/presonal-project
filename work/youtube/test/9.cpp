#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        bool m=0,c=0,u=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='m'){
                m=1;
                c=0;
                u=0;
            }
            else if(s[i]=='c'&&m==1){
                m=1;
                c=1;
                u=0;
            }
            else if(s[i]=='u'&&m==1&&c==1){
                m=1;
                c=1;
                u=1;
            }else{
               m=0;
                c=0;
                u=0; 
            }
            if(m&&c&&u){
                ans++;
                m=0;
                c=0;
                u=0;
            }
        }
        cout<<ans;

    }
}