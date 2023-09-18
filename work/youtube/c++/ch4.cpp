#include<iostream>
using namespace std;
int main(){
    int a[10]={};
    while(a[0]!=10){
        cout<<a[0]++;
    }

    do{
        cout<<"hi\n";
    }while(1!=1);

    cout<<endl;
    a[7]=100;
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        if(a[i]==0)
            continue;
        cout<<a[i]<<endl;
    }

    for(int i=0;i<500;i++){
        if(i==10)
            break;
        cout<<i;
    }
}