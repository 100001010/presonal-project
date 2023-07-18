#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,m,k=0;
    int line_1=0;
    while(cin>>n>>m&&n!=0&&m!=0){
        if(line_1++!=0){
            
            cout<<endl;
        }
        k++;
        vector<vector<int>> vec(n, vector<int>(m,0));
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='*'){
                    vec[i][j]=-1;
                    for(int vec_i=max(0,i-1);vec_i<=min(i+1,n-1);vec_i++)
                        for(int vec_j=max(0,j-1);vec_j<=min(j+1,m-1);vec_j++)
                            if(!(vec_i==i&&vec_j==j)&&vec[vec_i][vec_j]!=-1)
                                vec[vec_i][vec_j]++;
                }
            }
        }
        cout<<"Field #"<<k<<":\n";
        for (auto i: vec) {
            for (auto j: i) {
                if(j==-1)
                    cout<<"*";
                else
                    cout<<j;
            }
            cout<<endl;
        }

    }

}