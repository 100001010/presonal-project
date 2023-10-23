#include<iostream>
using namespace std;
int main(){
    int i=10;
    cout<<"i : "<<i<<",&i : "<<&i<<endl;
    int &ri=i;
    cout<<"ri: "<<ri<<",&ri: "<<&ri<<endl;

    ri=100;
    cout<<"ri: "<<ri<<" ,  i: "<<i<<endl;
    i=90;
    cout<<"ri: "<<ri<<" ,  i: "<<i<<endl;

    int *pi=&i;
    cout<<"pi: "<<pi<<" ,&pi: "<<&pi<<" ,*pi: "<<*pi<<endl;

    int a[3]={4,3,2};
    cout<<" a: "<<a<<" ,& a: "<<&a<<" ,* a: "<<*a<<"&a[0]"<<&a[0]<<endl;
    cout<<"a[1]:"<<a[1]<<" ,*(a+1)"<<*(a+1)<<endl;
    int n;
    cin>>n;
    int *p=new int[n];
    p[2]=4;
    cout<<*(p+2)<<p[2]<<endl;
}