#include<iostream>
using namespace std;

double cul_tick(double);

int main(){
    cout<<"請輸入目前本金:";
    int principal;
    cin>>principal;
    cout<<"請輸入目前手續費折數:";
    float principahandling_discountl;
    cin>>principahandling_discountl;

    double price;
    while(cout<<"請輸入目前股價",cin>>price){
        double tick=cul_tick(price);
        cout<<"檔位\t價格\t實收金額\t實收%數\t手續費\t交易稅\n";
        for(int i=-10;i<=10;i++){
            cout<<i<<"\t"
        }
    }
}

double cul_tick(double price){
    if(price<10)
        return 0.01;
    else if(price<50)
        return 0.05;
    else if(price<100)
        return 0.1;
    else if(price<500)
        return 0.5;
    else if(price<1000)
        return 1;
    else 
        return 5;
}