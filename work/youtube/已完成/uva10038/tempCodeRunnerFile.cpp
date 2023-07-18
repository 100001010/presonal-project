#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector <int> v;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp); 
        }

        set<int> s;
        for(int i=0;i<n-1;i++){
            s.insert(abs(v[i]-v[i+1]));
        }

        if(s.size()==v.size()-1&&s.count(1)&&s.count(n-1))
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
    
}