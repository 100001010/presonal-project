#include<iostream>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

long long int pow(int a,int b){
    queue <int> q;
    while(b!=0){
        cout<<b%2;
        q.push(b%2);
        b/=2;
    }
    cout<<endl;
    vector<int> v;
    v.push_back(a);
    int ans=1;
    for(int i=0;!q.empty();i++){
        if(i!=0){
            
            v.push_back(v[i-1]*v[i-1]);
            cout<<v[i]<<endl;
        }
        if(q.front()==1){
            ans*=v[i];
        }
        q.pop();

    }
    return ans;
}
int main(){
    cout<<pow(3,9);
}
