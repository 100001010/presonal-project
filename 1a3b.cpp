#include<iostream>
#include <math.h>
#include<cstdlib>
#include<ctime>
using namespace std;
 
 
int main()
{
    int Random[4],guess,Guess[4],A,B;
    A=0;
    B=0;
    srand( (unsigned)time(NULL) );
    
//    設定四位亂數
 
    for(int i=0;i<=3;i++){
        
        int j;
        
        do
        {
            Random[i]=rand() % 10;
            
            for (j=0; j<=i; j++) {
                if (Random[i]==Random[j]) {
                    break;
                }
            }
        }while(i!=j);
    }
    
    for (int i=0; i<=3; i++) {
        cout<<Random[i];
    }
    
 //   for(int i=0;i<=3;i++){
   //     cout<<Random[i];
     // }
    
    cout<<"\n";
    
//    版面設定
 
    cout<<"輸入的數字"<<"\t"<<"A"<<"\t"<<"B"<<"\n";
    
    while(A!=4){
    A=0;
    B=0;
        
//    輸入答案
    
    cin>>guess;
        
//    答案轉陣列
    for(int i=3;i>=0;i--){
        Guess[i]=guess % 10;//rest
        guess = guess/10;//quotion
 
    }
 
       
        
//    確認Ａ根Ｂ
 
    for(int i=0;i<=3;i++){
        if(Guess[i]==Random[i]){
            A++;
        }
    }
 
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(Guess[i]==Random[j])
                B++;
        }
    }
    B=B-A;
 
//    輸出幾Ａ幾Ｂ
     cout<<"\t"<<"\t"<<"\t"<<A<<"\t"<<B<<"\n";
    }
    
    cout<<"答對了";
    return 0;
}


