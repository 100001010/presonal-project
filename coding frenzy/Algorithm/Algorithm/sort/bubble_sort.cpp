#include<iostream>
#include<vector>
using namespace std;
#define size 5
void swap(int &a,int &b){
    int t;
    t=a;
    a=b;
    b=t;
}

int main(){
    int arr[size];
    for(int &i:arr)
        cin>>i;
    for(int i=0;i<size-1;i++){
        for(int j=size-2;j>=i;j--){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    for(int i:arr)
        cout<<i<<" ";
}