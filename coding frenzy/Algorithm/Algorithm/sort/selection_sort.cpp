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
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[i]>arr[j])
                swap(arr[i],arr[j]);
        }
    }
    for(int i:arr)
        cout<<i<<" ";
}