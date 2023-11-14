#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("white_list.txt","r",stdin);
    freopen("white_array.txt","w",stdout);
    string targat;
    while(getline(cin,targat)){
        int button=0;
        for(char i:targat){
            if(i=='\"'){
                cout<<"\"";
                button++;
                if(button>1)
                    break;
                continue;
            }
            if(button==1)
            cout<<i;
            
                
        }cout<<",";
    }
}