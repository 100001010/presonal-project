#include<iostream>
using namespace std;
int main(){
    int i1=1,i2=2;

    bool b;

    b=i1==1;
    cout<<b<<endl;
    b=i1!=1;
    cout<<b<<endl;
    b=i1!=1&&i1==1;
    cout<<b<<endl;
    b=i1!=1||i1==1;
    cout<<b<<endl;


    if(i1==1)
        cout<<"i1=1"<<endl;
    else 
        cout<<"i1!=1"<<endl;

    if(i1==1)
        if(i2==2)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    else if(i2==2)
        cout<<3<<endl;
    else
        cout<<4<<endl;

    switch (i2)
    {
    case 1:
        cout<<1<<endl;
        break;
    
    case 2:
        cout<<2<<endl;
        break;
    default:
        cout<<"f"<<endl;
        break;
    }
}