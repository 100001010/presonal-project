#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,kase=0;
    while(cin>>n){
        kase++;
        vector<int>v;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            v.push_back(t);
        }
        
        set<int> s;
        bool ans=1;
        for(int i=0;i<n-1;i++){
            if(v[i]<1||v[i]>=v[i+1])
                ans=0 ;      
        }
        for(int j=0;j<n;j++)
            for(int i=0;i<=j;i++){
                if(s.count(v[j]+v[i]))
                    ans=0;  
                else 
                    s.insert(v[j]+v[i]);
            }
        if(ans)
            cout<<"Case #"<<kase<<": It is a B2-Sequence.\n\n";
        else
            cout<<"Case #"<<kase<<": It is not a B2-Sequence.\n\n";
    }

}