#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a,b;
    while(cin>>a>>b&&(a!=0||b!=0)){
        int n=0;
        for(int i=1;i*i<=b;i++)
            if(i*i>=a)
                n++;
        cout<<n<<endl;
    }
}

