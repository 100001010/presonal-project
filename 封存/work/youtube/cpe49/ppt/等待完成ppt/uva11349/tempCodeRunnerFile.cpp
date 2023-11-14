#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

int main(){
    int n;
    string s;
    for(int k=1;cin>>s>>s>>s;k++){
        stringstream stoi;
        stoi<<s;
        stoi>>n;
        int t;
        stack<int> sta;

        for(int i=0;i<n/2&&cin>>t;i++ ){
            sta.push(t);
        }

        if(n%2==1)
            cin>>t;
        bool ans=1; 
        while(!sta.empty()){
            cin>>t;
            if(t==sta.top()){
                ans=0;
            }
            sta.pop();
        }
        cout<<"Test #"<<k<<": ";
        if(ans)
            cout<<"Symmetric.\n";
        else    
            cout<<"Non-symmetric.\n";


    }
}