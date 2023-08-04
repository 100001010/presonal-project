#include<iostream>
#include<string>
#include<set>
using namespace std;
string find_plate(string targat){
    string r;
    int b=0;
    for(char i:targat){
        if(i=='\''){
            b++;
            continue;
        }
        if(b==1){
            r+=i;
        }
    }
    return r;
}

int main(){
    freopen("../ch1/ch1.txt","r",stdin);
    freopen("../ch1/find_plate_1.txt","w",stdout);
    for(int jj=0;jj<250;jj++){
        string s;
        set <string> se;
        bool find_white=0;
        while(getline(cin,s)&&s!=""){

            if(s[23]=='w'&&!find_white){
                find_white=1;
                cout<<find_plate(s);
                
            }
            se.insert(find_plate(s));
                
        }
        
        if(!find_white){
            for(string i:se)
                cout<<i<<",";
        }
            
        cout<<endl;
    }
    
}
