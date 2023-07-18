#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> bin;
    int in;
    while(cin>>in,in!=0){
        int num=0;
        while(in!=0){
            bin.push(in%2);
            if(in%2)
                num++;
            in/=2;
        }
        cout<<"The parity of ";
        while(!bin.empty()){
            cout<<bin.top();
            bin.pop();
        }
        cout<<" is "<<num<<" (mod 2)."<<endl;
    }
}

