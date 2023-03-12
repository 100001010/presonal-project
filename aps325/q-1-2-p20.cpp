#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int f();
int g();
int h();
int main(){
        string s;cin>>s;
        if(s=="f")
            cout<< f();
        else if(s=="g")
            cout<< g();
        else if(s=="h")
            cout<< h();

}

int f(){
    string s;cin>>s;
    if(s=="f")
        return 2*f()-3;
    else if(s=="g")
        return 2*g()-3;
    else if(s=="h")
        return 2*h()-3;
    else{
        int nx=atoi(s.c_str());
        return 2*nx-3;
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
        else if(s=="h")
            gx[i]=h();
        else
            gx[i]=atoi(s.c_str());
    }       
    return 2*gx[0]+gx[1]-7;
}

int h(){
    int hx[3]={};
    for(int i=0;i<3;i++){
        string s;cin>>s;
        if(s=="f")
            hx[i]=f();
        else if(s=="g")
            hx[i]=g();
        else if(s=="h")
            hx[i]=h();
        else
            hx[i]=atoi(s.c_str());
    }       
    return 3*hx[0]-2*hx[1]+hx[2];
}