#include<iostream>
#include<string>
#include<map>
#include<iomanip>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int k;
    cin>>k;
    string s;
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<k;i++){
        if(i!=0)
            cout<<endl;
        map<string,float> map;
        int total=0;
        while(getline(cin,s),s!=""){
            map[s]++;
            total++;
        }
        for(const auto& j : map){
            cout<<j.first<<" "<<fixed<<setprecision(4)<<j.second/total*100<<endl;
        }
    }
}