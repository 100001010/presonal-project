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
    string s;cin>>s;
    int canum=1;
    while(cin>>s){
        #define ps(i) s[s.size()-i+1]//ps = palindrome_string
        vector<vector<int>> vec(s.size()+1,vector<int>(s.size()+1));
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=s.size();j++){
                //if(!(i==0||j==0))
                //    cout<<s[j-1]<<" "<<ps(i-1)<<endl;
                if(i==0||j==0){
                    vec[i][j]=i+j;
                }else if(s[j-1]==ps(i-1)){
                    
                    vec[i][j]=vec[i-1][j-1];
                }else{
                    vec[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1;
                }
                //cout<<vec[i][j]<<" ";
            }
            //cout<<endl;
        }

        cout<<"Case "<<canum++<<": "<<vec[s.size()][s.size()]/2<<endl;
    }
}