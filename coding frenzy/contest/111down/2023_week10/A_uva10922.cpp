#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    while(cin>>s,s[0]!='0'){
        int total=0,degree=0;
        for(int i:s)
            total+=i-48;
        
        if(total%9!=0){
            cout<<s<<" is not a multiple of 9."<<endl;
            continue;
        }
            
        int next_total=0;

        degree++;
        while(!(total<10||total%9!=0)){
            while(total!=0){
                next_total+=total%10;
                total/=10;
            }
            swap(next_total,total);
            degree++;
        }
        

        cout<<s<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;

            
    }
}