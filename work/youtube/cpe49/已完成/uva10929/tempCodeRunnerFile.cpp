#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    string s;
    while(cin>>s,s!="0"){
        cout<<s;
        int n=0,multiple=0;
        for(int i:s){
            n++;
            i-='0';
            multiple+=i*pow(-1,n);  
        }
        if(multiple%11==0)
            cout<<"is a multiple of 11.\n";
        else    
            cout<<"is not a multiple of 11.\n";
    }
}