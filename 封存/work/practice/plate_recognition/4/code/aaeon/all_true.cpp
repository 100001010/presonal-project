#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("../ch1/ch1.txt","r",stdin);
    freopen("../ch1/all_true1.txt","w",stdout);
    for(int jj=0;jj<250;jj++){
        string s;
        bool find_white=0;
        while(getline(cin,s)&&s!=""){

            if(s[23]=='w'){
                find_white=1;
                
            }
                
        }
        cout<<find_white;
            
        cout<<endl;
    }
    
}
