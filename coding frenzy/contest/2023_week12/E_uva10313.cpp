#include<string>
#include<iostream>
#include <sstream>
#include<vector>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    long long int a[301][301] = {};
    for(int i=0;i<=300;i++)
        for(int j=0;j<=300;j++){
            if(i==0||j==0){a[i][j]=0;continue;}
            if(j==1||i==j||i-j==1){a[i][j]=1;continue;}
            if(j>i) {a[i][j]=0;continue;}

            long long int total=0,n = i-j;
            for(int k=1;k<=j;k++)
                total+=a[n][k];
            
            a[i][j]=total;
            if(i==3&&j==2)a[i][j]=1;
        }
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int input;
        vector <int> N;
        while (ss >> input)
            N.push_back(input);
        if(N[0]==0){
            if(N.size()==1){
                cout<<1<<endl;
                continue;
            }
            if(N.size()==2){
                cout<<1<<endl;
                continue;
            }
            if(N.size()==3){
                if((N[1]<N[2]&&N[2]<=1)||(N[1]==0&&N[2]==0))
                    cout<<1<<endl;
                else 
                    cout<<0<<endl;
                continue;
            }
        }
        if(N.size()==1){
            long long int total=0;
            for(long long i:a[N[0]])
                total+=i;
            cout<<total<<endl;
        }
        if(N.size()==2){
            if(N[1]>N[0])
                N[1]=N[0];
            long long int total=0;
            for(int i=1;i<=N[1];i++)
                total+=a[N[0]][i];
            cout<<total<<endl;
        }
        if(N.size()==3){
            if(N[2]>N[0])
                N[2]=N[0];
            if(N[1]>N[0]){
                cout<<0<<endl;
                continue;
            }
            long long int total=0;
            for(int i=N[1];i<=N[2];i++)
                total+=a[N[0]][i];
            cout<<total<<endl;
        }
    }
        
}