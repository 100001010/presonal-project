#include<iostream>
using namespace std;
void hi();
int  add(int ,int); //call by vaule
int  swap(int &,int &);//call by refrence
int  swap(int *,int *);//call by pointer

int main(){
    //hi();
    int a=10,b=20;
    cout<<add(a,b)<<endl;
    cout<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}


void hi(){
    cout<<"hi"<<endl;
}
int add(int z,int b){
    z=100;
    return z+b;
}
int swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
int swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}