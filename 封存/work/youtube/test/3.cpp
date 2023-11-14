#include<iostream>
using namespace std;

bool prime(int p){
    for(int i=2;i*i<=p;i++)
        if(p%i==0)
            return 0;
    return 1;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0,j=2;i<n;j++){
            if(prime(j)){
                cout<<j<<",";
                i++;
            }
        }
    }
}





/*
n=5
2,3,5,7,11:i

1,2,3,4,5,6,7,8,9,10:j
n,y,y,n,y,n,y,n,n,n
2,3,5,7

6
2,3,


100
10
1,2,5,10,20,50,100

100 =10*10
10= 2*5
*/    
