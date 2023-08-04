#include<iostream>
using namespace std;
int main(){
    int n,x1,y1,x2,y2;
    for(int k=1;cin>>x1>>y1>>x2>>y2;k++){
        int ans=0;
        while(!(x1!=x2&&y1!=y2)){
            ans++;
            if(x1==0){
                y1=x1+1;
                x1=0;
            }else{
                y1--;
                x1++;
            }
        }
        cout<<ans<<endl;
    }
}