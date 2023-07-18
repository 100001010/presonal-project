#include<iostream>
#include<string>
using namespace std;
int main(){
    int N;
    while(cin>>N,N!=0){
        int e=4,s=5,w=3,n=2,t=1,b=6;
        for(int i=0;i<N;i++){
            string str;
            cin>>str;
            int temp;
            if(str[0]=='n'){
                temp=t;
                t=s;
                s=b;
                b=n;
                n=temp;

            }
            if(str[0]=='s'){
                temp=t;
                t=n;
                n=b;
                b=s;
                s=temp;

            }
            if(str[0]=='e'){
                temp=t;
                t=w;
                w=b;
                b=e;
                e=temp;

            }
            if(str[0]=='w'){
                temp=t;
                t=e;
                e=b;
                b=w;
                w=temp;

            }
        }
        cout<<t<<endl;
    }
    return 0;
}