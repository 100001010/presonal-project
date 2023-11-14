#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    double ax,ay,bx,by,cx,cy,dx,dy;
    while(cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy){
        double ansx=0,ansy=0;
        if(cx==bx&&cy==by){
            ansx=dx-cx+ax;
            ansy=dy-cy+ay;
        }else if(cx==ax&&cy==ay){
            ansx=dx-cx+bx;
            ansy=dy-cy+by;
        }else if(dx==bx&&dy==by){
            ansx=cx-dx+ax;
            ansy=cy-dy+ay;
        }else{
            ansx=cx-dx+bx;
            ansy=cy-dy+by;
        }
        cout<<fixed<<setprecision(3)<<ansx<<" "<<ansy<<endl;
    }  
}