#include<iostream>
#include<string>
using namespace std;
char out(char in){
    string dec="`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    for(int i=0;i<dec.size();i++){
        if(dec[i]==in)
            return dec[i-2];
    }
}
int main(){
    string in;
    while(getline(cin,in)){
        for(char i:in){
            if(i==' ')
                cout<<" ";
            else    
                cout<<out(i);
        }
        cout<<endl;
    }
}