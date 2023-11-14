#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("2.txt","r",stdin);
    freopen("2.csv","w",stdout);
    string s;
    long int total,next_total=0;
    bool t=0;
    while(getline(cin,s)){
        if(t==1){
            for(int i=1;i<=20;i++)

                    cout<<s[i];
            t=0;
            cout<<endl;
        } 
        if(s.size()<3){
            t=1;

        }
         
          
    }
}
