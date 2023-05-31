#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int ta,n;cin>>ta;
    while(cin>>ta>>n){
        vector<int>vec;
        bool b=0;
        for(int i=0;i<n;i++){
            int t;cin>>t;
            if(t==ta){
                b=1;
                break;
            }
            if(t<ta)vec.push_back(t);

        }
        if(b){
            cout<<"YES/n";
            continue;
        }

        sort(vec.begin(),vec.end());

        int sum=0;

        for(int i:vec){
            if(sum<ta){
               sum+=i; 
            }
        }
        
    }
}