#include<iostream>
#include<cmath>
#include<vector>
#define ll long long 
using namespace std;
ll int fh(ll int p[],ll int head,ll int end);
int main(){
    ll int N,L;cin>>N>>L;
    ll int p[N+2];
    p[0]=0;
    for(int i=1;i<=N;i++) {
        cin>>p[i];
    }
    p[N+1]=L;
    cout<<fh(p,0,N+1);
}
ll int fh(ll int p[],ll int head,ll int end){
    if(end-head<=1)    return 0;
    ll int mid=(0LL+p[end]+p[head])/2;
    ll int n=head;
    for(int i=head;i<=end;i++)
        if(abs(mid-p[n])>=abs(mid-p[i])){
            n=i;
        }
    return (p[end]-p[head])+fh(p,head,n)+fh(p,n,end);
}

