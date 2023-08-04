#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("1.txt","r",stdin);
    string s;
    long int total,next_total=0;
    bool t=0;
    while(getline(cin,s)){
        if(t==1){
            for(int i=1;i<21;i++)
                cout<<s[i];
            cout<<endl;
            //cout<<s[13]<<s[14]<<s[15]<<s[16]<<s[17]<<s[18]<<s[19]<<s[20]<<endl;
            t=0;
        } 
        if(s.size()<3){
            t=1;

        }
         
          
    }
}
