#include<iostream>
#include<string>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string a,b ;
    while(getline(cin,a),getline(cin,b)){
        int a_arry[2][128]={};
        for(char i:a){
            a_arry[0][i]++;
        }
        for(char i:b){
            a_arry[1][i]++;
        }
        for(int i=0;i<128;i++){
            for(int j=0;j<min(a_arry[0][i],a_arry[1][i]);j++)
                cout<<char(i);
        }
        cout<<endl;
    }
}