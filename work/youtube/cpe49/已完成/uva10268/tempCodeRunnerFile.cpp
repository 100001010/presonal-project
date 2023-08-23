#include<iostream>
#include<vector>
#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
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
            if(((v.size()-i-1)-1)%2==1)
                total+= v[i]*(v.size()-i-1)*pow(x,((v.size()-i-1)-1)/2)*pow(x,((v.size()-i-1)-1)/2)*x;
            else 
                total+= v[i]*(v.size()-i-1)*pow(x,((v.size()-i-1)-1)/2)*pow(x,((v.size()-i-1)-1)/2);
        }
        cout<<total<<endl;
    }
}