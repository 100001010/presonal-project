#include<iostream>
using namespace std;
int main(){
    int a[43]={1,2},n=3;
    for(int i=2;i<43;i++,n++){
        a[i]=a[i-1]+a[i-2];
        if(a[i]>=1000000000)
            break;
    }
    for(int i:a)
        cout<<i<<",";
}