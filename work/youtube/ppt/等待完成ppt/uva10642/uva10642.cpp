#include<iostream>
using namespace std;
int main(){
    int n,x1,y1,x2,y2;cin>>n;
    for(int k=1;cin>>x1>>y1>>x2>>y2;k++){
        int oto1=0,oto2=0;
        oto1 =(1+x1+y1)*(x1+y1)/2+(x1+y1)-y1;
        oto2 =(1+x2+y2)*(x2+y2)/2+(x2+y2)-y2;


        cout<<"Case "<<k<<": "<<oto2-oto1<<endl;
    }
}