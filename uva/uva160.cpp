#include<iostream>
using namespace std;
int main(){
    #ifdef fre
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    while(cin>>n&&n!=0){
        int ans[100]={};
        printf("%3d! =",n);
        for(int i=2;i<=n;i++){
            int tempi = i;
            while(tempi!=1){
                for(int j=2;j<=tempi;j++){
                    if(tempi%j==0){
                        tempi/=j;
                        ans[j]++;
                        break;
                    }
                }
            }
        }
        int num=0;
        for(int i=1;i<100;i++){
            
            if(ans[i]!=0){
                if(num++%15==0 &&num!=1)
                    cout<<endl<<"      ";
                printf("%3d",ans[i]);
            }
                
        }

        cout<<endl;
    }
}





