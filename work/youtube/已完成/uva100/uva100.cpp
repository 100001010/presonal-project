#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int b,e;
    while(cin>>b>>e){
        cout<<b<<" "<<e<<" ";
        if(b>e)
            swap(b,e);

        int max_ans=-1;
        for(int i=b;i<=e;i++){
            int ans=0,temp=i;
            while(temp!=1){
                ans++;
                if(temp%2==1)
                    temp=temp*3+1;
                else 
                    temp/=2;
            }
            if(max_ans<ans)
                max_ans=ans;
        }
        cout<<max_ans+1<<endl;//包含自己

    }
}

