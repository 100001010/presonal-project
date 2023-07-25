#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    vector<string> v;
    string s;
    int max_size=-1,max_size_path=-1;
    for(int i=0;getline(cin,s);i++){
        v.push_back(s);

        if((int)v[i].size()>max_size){
            max_size_path=i;
            max_size=v[i].size();
        }
    }
    
    for(int i=0;i<max_size;i++){
        for(int j=v.size()-1;j>=0;j--)
            if(v[j][i]>0&&i<v[j].size())
                cout<<v[j][i];
            else{
                cout<<" ";
            }
                
        cout<<endl;
    }
    
        
}