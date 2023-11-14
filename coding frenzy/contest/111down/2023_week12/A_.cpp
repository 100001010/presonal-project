#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    getline(cin, s);

    while (getline(cin, s)){
        vector<string> vec;
        vector<double> time;

        string in;
        
        while(getline(cin,in) && in.size() != 0){
            vec.push_back(in);  
        }
        sort(vec.begin(),vec.end());

        double total=1;
        string up;up=vec[0];time.push_back(1);
        for(int i=1;i<vec.size();i++){
            if(up==vec[i]){
                time[time.size()-1]++;
            }else{
                
                time.push_back(1);
                up=vec[i];
            }
            total++;
        }
        up=vec[0];cout<<vec[0]<<" "<<time[0]/total<<endl;
        int j=1;
        for(int i=1;i<vec.size();i++){
            if(up==vec[i]){
                continue;
            }else{
                cout<<vec[i]<<" "<<time[j++]/total<<endl;
            }
        }
        cout<<endl;
    }
}