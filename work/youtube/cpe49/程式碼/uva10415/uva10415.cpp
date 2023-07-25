#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;cin>>s;
    while(cin>>s){
        cout<<s;
        int ans[11]={},next_ans[11]={};
        bool first =1;
        for(char c:s){
            int temp[11]={};
            if(c=='c'){
                for(int i=2;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                    
                        
                        
                for(int i=7;i<=10;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                    
                
            }else if(c=='d'){
                for(int i=2;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                for(int i=7;i<=9;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                
            }else if(c=='e'){
                for(int i=2;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                for(int i=7;i<=8;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                
            }else if(c=='f'){
                for(int i=2;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                temp[7]++;
                if(next_ans[7]==0){
                        ans[7]++;
                    }
                
            }else if(c=='g'){
                for(int i=2;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='a'){
                for(int i=2;i<=3;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='b'){
                for(int i=2;i<=2;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                    

            }else if(c=='C'){
                for(int i=3;i<=3;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='D'){
                for(int i=1;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                for(int i=7;i<=9;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='E'){
                for(int i=1;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                for(int i=7;i<=8;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='F'){
                for(int i=1;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                temp[7]++;
                if(next_ans[7]==0){
                        
                    ans[7]++;
                }
                
            }else if(c=='G'){
                for(int i=1;i<=4;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
                
            }else if(c=='A'){
                for(int i=1;i<=3;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }else if(c=='B'){
                for(int i=1;i<=2;i++){
                    temp[i]++;
                    if(next_ans[i]==0){
                        ans[i]++;
                    }
                }
            }
            for(int i=1;i<11;i++){
                next_ans[i]=temp[i];
            }
        }
        for(int i=1;i<11;i++){
            cout<<ans[i]<<" ";
        }
    }
}