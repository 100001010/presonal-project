#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int arr[1000000010]={};
int main(){
    #ifdef fre
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    vector <int>vec;
    
    
    int r,t;
    cin>>r;
    for(int e=0;e<r;e++){
        cin>>t;
        int a,max=0;
            
        for(int w=0;w<t;w++){
            cin>>a;
            vec.push_back(a);
        arr[a]++;
        if(arr[a]==2){
            if(max<vec.size()-1)
                max=vec.size()-1;
            for(;vec[0]!=a;){
                arr[vec[0]]--;
                vec.erase(vec.begin());
            }
            arr[vec[0]]--;
            vec.erase(vec.begin());
        }
        
    }
    if(vec.size()>max)
        cout<<vec.size()<<endl;
    else
        cout<<max<<endl;
    
        }
        

}