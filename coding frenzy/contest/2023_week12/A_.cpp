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
    getline(cin, s);getline(cin, s);

    while (getline(cin, s))
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
                total++;
                time.push_back(1);
                up=vec[i];
            }
        }
        up=vec[0];
        for(int i=1;i<vec.size();i++){
            if(up==vec[i]){
                continue;
            }else{
                cout<<vec[i]<<" "<<time[i]/total<<endl;
            }
        }
        cout<<endl;
    }
}