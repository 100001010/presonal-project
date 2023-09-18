#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        int a[10]={};
        for(int i=0;i<10;i++){
            cin>>a[i];
            if(a[i]==-1){
                a[i]=0;
                break;
            }
        }

        sort(a,a+10);

        
        for(int i=0;i<10;i++){
            if(a[i]!=0)
                cout<<a[i]<<",";
        }
        cout<<endl;
    }
}