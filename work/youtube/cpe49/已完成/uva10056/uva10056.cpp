#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,i;
    cin>>n;
    float p;
    while(cin>>n>>p>>i){
        float c=0;
        for(int j=0;j<n;j++){
            c+=pow((1-p),j);
            //cout<<pow((1-p),j)<<endl;
        }
        //cout<<c<<endl;
        if(p==0)
            cout<<"0.0000\n";
        else
            cout  <<fixed<<  setprecision(4)  << (1/c)*pow((1-p),i-1)  <<  endl;


    }
}