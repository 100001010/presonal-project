#include<iostream>
#include<cmath>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    long long int s,d;
    while(cin>>s>>d){
        long long int total=0;
        for(s;total<d;s++)
            total+=s;
        cout<<s-1<<endl;
    }
}
