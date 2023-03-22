#include<string>
#include<iostream>
using namespace std;
int main(){
    #ifdef fre
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int n=0;
    string str;
    while(getline(cin,str)){
        n++;
        if(n!=1)
            cout<<endl;
        int a[129]={};

        for(char i: str)
            a[int (i)]++;

        for(int i=1;i<1000;i++){
            for(int j=128;j>=0;j--){
                if(a[j]==i){
                    cout<<j<<" "<<i<<endl;
                }
            }
        }
        
    }

}