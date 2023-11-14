#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long int in,base;
    while(cin>>in>>base){
        queue<long long int> que;
        que.push(in);
        while(base!=0&&in%base==0){
            que.push(in/=base);
        }
        if(in<base&&in==1){
            do{
                cout<<que.front()<<" ";
                que.pop();
            }while(!que.empty());
            cout<<endl;
        }else{
            cout<<"Boring!\n";
        }
    }
}

