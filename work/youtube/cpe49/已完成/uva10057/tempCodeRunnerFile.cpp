#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    while(cin>>n){
        vector<int> v(n);
        for(int &i:v){
            cin>>i;
        }
        sort(v.begin(),v.end());
        if(n%2==0){
            cout<<v[n/2-1]<<" ";
            int num=0;
            for(int i:v)
                if(i==v[n/2-1]||i==v[n/2])
                    num++;
            cout<<num<<" "<<v[n/2]-v[n/2-1]+1<<endl;

        }else{
            cout<<v[n/2]<<" ";
            int num=0;
            for(int i:v)
                if(i==v[n/2])
                    num++;
            cout<<num<<" "<<1<<endl;;
            
            
        }
    }
}
