#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int f();
int g();
int gx();
int main(){
    while(1){
        string s;cin>>s;
        if(s=="f")
            cout<< f();
        else if(s=="g")
            cout<< g();

    }
    

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
    return gx()+2*gx()-3;
}

int gx(){
    string s;cin>>s;
    if(s=="f")
        return f();
    else if(s=="g")
        return g();
    else{
        int n=atoi(s.c_str());
        return n;
    }
}
