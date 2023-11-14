#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        if(s[2]=='+')
            cout<< (s[0]-'0')*10+(s[1]-'0')+(s[3]-'0')*10+(s[4]-'0')<<endl;
        if(s[2]=='-')
            cout<< (s[0]-'0')*10+(s[1]-'0')-(s[3]-'0')*10+(s[4]-'0')<<endl;
        if(s[2]=='*')
            cout<< ((s[0]-'0')*10+(s[1]-'0'))*((s[3]-'0')*10+(s[4]-'0'))<<endl;
        if(s[2]=='/')
            cout<< ((s[0]-'0')*10+(s[1]-'0'))/((s[3]-'0')*10+(s[4]-'0'))<<endl;
    }
}

/*
id 01234
s= 90+25
*/