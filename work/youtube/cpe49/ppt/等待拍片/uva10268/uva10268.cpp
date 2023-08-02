#include<iostream>
#include<vector>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
long long int pow(int a,int b){
    queue <int> q;
    while(b!=0){
        q.push(b%2);
        b/=2;
    }
    vector<long long int> v;
    v.push_back(a);
    long long int ans=1;
    for(int i=0;!q.empty();i++){
        if(i!=0){
            v.push_back(v[i-1]*v[i-1]);
        }
        if(q.front()==1){
            ans*=v[i];
        }
        q.pop();

    }
    return ans;
}
int main(){
     #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int x;
    string t;
    while(cin>>x&&getline(cin,t)){
        vector<int> v;        
        getline(cin,t);
        stringstream ss(t);
        int i_t;
        while(ss>>i_t){
            v.push_back(i_t);
        }
        long long int total=0;
        for(int i=0;i<v.size()-1;i++){
            total+= v[i]*(v.size()-i-1)*pow(x,(v.size()-i-1)-1);
        }
        cout<<total<<endl;
    }
}