#include<iostream>
#include<cmath>
using namespace std;
bool p(int n){
    for(int i=2;i<=sqrt(n);i++){
         if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
        while(cin>>n){
            cout<<n;
            bool prime=1,emirp=1;
            prime = p(n);
            if(prime){
                int invert_n=0,t_n=n;
                while(t_n>0){
                    invert_n = invert_n*10+t_n%10;
                    t_n/=10; 
                }
                emirp = p(invert_n)&&invert_n!=n;
                if (emirp){
                    cout<<" is emirp.\n";
                }else{
                    cout<<" is prime.\n";
                }

            }else{
                cout<<" is not prime.\n";
            }
        }
}