#include<iostream>
using namespace std;
#define size 4
int find(int *p,int t){
    for(int i=0;i<size;i++){
        if(*(p+i)==t)
            return i;
    }
}

int main(){
    int v[size];
    int p[size];

    for(int &i:v)
        cin>>i;
    for(int i=0;i<size;i++)
        p[i]=i;
    

    for(int i=1;i<size;i++){
        int j=i-1;
        for(;j>=0;j--){
            if(v[find(p,j)]>=v[i]){
              break;  
            }
        }
        for(int k=0;k<size;k++){
            if(p[k]>j&&p[k]<i)
                p[k]++;
        }
                p[i]=j>0?j:0;
    }
    for(int i=0;i<size;i++){
        cout<<v[find(p,i)]<<' ';
    }
    
}
