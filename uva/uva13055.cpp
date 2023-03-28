//ok
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int qweqwe;cin>>qweqwe;
    stack <string> sta;
    for(int qwerqwer=0;qwerqwer<qweqwe;qwerqwer++){
        string str;cin>>str;
        
        if(str == "Sleep"){
            cin>>str;
            sta.push(str);
            //cout<<str<<endl;
        }else if(str == "Test"){
            if(!sta.empty())
                cout<<sta.top()<<endl;
            else
                cout<<"Not in a dream\n";
        }else{
            if(!sta.empty())
                sta.pop();
        }
    }

}