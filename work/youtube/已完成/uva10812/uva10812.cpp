#include<iostream>
using namespace std;
int main(){
    int a,b;cin>>a;
    while(cin>>a>>b){
        if((a+b)%2==1||a<b){
            cout<<"impossible\n";
        }else{
            cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
        }
    }
}
