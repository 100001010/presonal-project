#include<iostream>
using namespace std;
int main(){

    int b,e;cin>>b;
    for(int kase=1;cin>>b>>e;kase++){

        int total=0;
        for(b=b/2*2+1;b<=e;b+=2){
            total+=b;
        }

        cout<<"Case "<<kase<<":"<<total<<endl;
    }
    
}

