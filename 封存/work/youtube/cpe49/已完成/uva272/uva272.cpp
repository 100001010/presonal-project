#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    int time=1;
    while(getline(cin,s)){
        for(char i:s){
            if(i=='"')
                if(time++%2==1)
                    cout<<"``";
                else
                    cout<<"''";
            else
                cout<<i;
        }
        cout<<endl;
    }
}