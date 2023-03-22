#include<string>
#include<iostream>
using namespace std;
int main(){
    #ifdef fre
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int n=0;
    string str;
    while(getline(cin,str)){
        n++;
            

        for(char i: str)
            cout<<char(i-7);
        cout<<endl;
    }

}