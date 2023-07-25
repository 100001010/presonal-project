#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    getline(cin,s);
    while(1){
        map<string,int> map;
        while(getline(cin,s)&&s!=""){
            map[s]++;
            
            cout<<map[s]<<" "<<1;
        }

        cout<<"asfd";
    }
}