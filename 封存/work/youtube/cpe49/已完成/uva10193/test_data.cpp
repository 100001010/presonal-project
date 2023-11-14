#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    srand(time(NULL));
    int num=100;
    cout<<num<<endl;
    for(int i=0;i<num;i++){
        for(int j=0;j<2;j++){
            int l=9;
            cout<<1;
            for(int k=0;k<l;k++)
                cout<<rand()%2;
            cout<<endl;
        }
    }
}