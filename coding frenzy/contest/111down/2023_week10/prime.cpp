#include<iostream>
using namespace std;
int main(){
    int n=0;
    for(int i=2;i<=2001;i++){
        int j=2;
        for(;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(i-j==0){
            cout<<i<<",";n++;
        }
    }
    cout<<endl<<n;
}