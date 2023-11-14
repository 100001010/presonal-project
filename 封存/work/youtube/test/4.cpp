#include<iostream>

using namespace std;
int main(){
    while(1){
        char c;
        int ans[128]={};
        while(cin>>c,c!='0'){
            ans[int(c)]++;
        }
        for(int i=0;i<128;i++){
            if(ans[i]!=0)
                cout<<char(i)<<":"<<ans[i]<<endl;
        }
        cout<<endl;
    }

    
}


/*
ASCII =128
'0'=48
'A'=65
'a'=97
*/