#include<iostream>
#include<string> 
using namespace std;

int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    while(getline(cin,s)){
        int totalnum=0,ans=1,t;
        for(char &i:s){
            t=0;
            if('a'<=i&&i<='z'){
                t=i-'a'+36;
            }else if('A'<=i&&i<='Z'){
                t=i-'A'+10;
            }else if('0'<=i&&i<='9'){
                t=i-'0';
            }
            if(t>ans)
                ans=t;
            totalnum+=t;
        }
        for(ans;ans<=62;ans++){
            if(totalnum%(ans)==0){
                cout<<ans+1<<endl;
                break;
            }
        }
        if(ans==63)
            cout<<"such number is impossible!\n";
    
    }
}