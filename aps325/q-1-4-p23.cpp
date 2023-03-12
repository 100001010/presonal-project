#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int cut_point(vector<int>&p){
    int total_min=0x7fffffff,total_temp=0,min_point=0;
    for(int m=1;m<p.size()-1;m++){
        total_temp=0;
        for(int i=0;i<p.size();i++){
            total_temp+=p[i]*abs(i-m);
        }
        if(total_temp<total_min){
            swap(total_min,total_temp);
            min_point=m;
        }
        
    }
    //cout<<p[min_point]<<endl;
    return min_point;
}
int cut(vector<int> &p,int k){
    if(k==0||p.size()<3){
        return 0;
    }else{
        int cut_addres=cut_point(p);
        k--;
        vector <int> pf(p.begin(),p.begin()+cut_addres-1);
        vector <int> pe(p.begin()+cut_addres+1,p.end());
        //cout<<p[cut_addres]<<endl;
        return p[cut_addres]+cut(pf,k)+cut(pe,k);
    }
}

int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    vector<int> p ;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        p.push_back(t);
    }

    cout<<cut(p,k);
}