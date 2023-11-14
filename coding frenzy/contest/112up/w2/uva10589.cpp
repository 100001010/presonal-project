#include<iostream>

using namespace std;
int main(){
    int n,a;
    while(cin>>n>>a&&a!=0&&n!=0){
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            double x2,y2;
            x2=(x>a/2? x*x:(x-a)*(x-a));
            y2=(y>a/2? y*y:(y-a)*(y-a));
            if(x2+y2>a*a)
        }
    }
}