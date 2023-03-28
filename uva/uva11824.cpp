//ok
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.text","w",stdout);
    #endif
    int qazqaz;cin>>qazqaz;
    for(int qwsqws=0;qwsqws<qazqaz;qwsqws++){
        long long int in;
        vector<long long int>vec;
        while(cin>>in,in!=0){
            vec.push_back(in);
        }
        sort(vec.begin(),vec.end());

        long long int total=0;
        for(int i=vec.size()-1;i>=0;i--){
            total+=pow(vec[i],vec.size()-i);
        }
        
        if(2*total>5000000||2*total<0)
            cout<<"Too expensive"<<endl;
        else 
            cout<<2*total<<endl;
    }
}
