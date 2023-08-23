#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    while(cin>>n){
        vector<int> vec(n);
        for(int &i:vec)
            cin>>i;
        int ans=0;
        for(int i=vec.size()-1;i>=0;i--){
            for(int j=0;j<i;j++){
                if(vec[j]>vec[j+1])
                    swap(vec[j],vec[j+1]);
                    ans++;
            }
        }
        cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
    }   
}