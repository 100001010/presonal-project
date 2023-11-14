#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    long long int n;
    string s;cin>>s;
    for(int k=1;cin>>s>>s>>s;k++){
        stringstream stoi;
        stoi<<s;
        stoi>>n;
        long long int t;
        stack<long long int> sta;
        bool ans=1;
        //cout<<n<<endl;
        for(int i=1;i<=n*n/2;i++ ){
            //cout<<"hi";
            cin>>t;
            if(t<0)
                ans=0;
            sta.push(t);
        }

        if(n%2==1)
            if(cin>>t&&t<0)
                ans=0;
         
        while(!sta.empty()){
            cin>>t;
            if(t!=sta.top()){
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