#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int f();
int g();
int main(){
        string s;cin>>s;
        if(s=="f")
            cout<< f();
        else if(s=="g")
            cout<< g();

}

int f(){
    string s;cin>>s;
    if(s=="f")
        return 2*f()-1;
    else if(s=="g")
        return 2*g()-1;
    else{
        int nx=atoi(s.c_str());
        return 2*nx-1;
    }

}

int g(){
    int gx[2]={};
    for(int i=0;i<2;i++){
        string s;cin>>s;
        if(s=="f")
            gx[i]=f();
        else if(s=="g")
            gx[i]=g();
        else
            gx[i]=atoi(s.c_str());
    }       
    return gx[0]+2*gx[1]-3;
}