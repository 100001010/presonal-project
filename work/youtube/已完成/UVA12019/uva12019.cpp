#include<iostream>
using namespace std;
int main(){
    int m,d;cin>>m;
    int num_day[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    while(cin>>m>>d){
        int total_day=d;
        for(int i=0;i<m-1;i++){
            total_day+=num_day[i];
        }
        int day=(total_day+5)%7;
        switch (day)
        {
        case 0:
            cout<<"Sunday\n";
            break;
        case 1:
            cout<<"Monday\n";
            break;
        case 2:
            cout<<"Tuesday\n";
            break;
        case 3:
            cout<<"Wednesday\n";
            break;
        case 4:
            cout<<"Thursday\n";
            break;
        case 5:
            cout<<"Friday\n";
            break;
        case 6:
            cout<<"Saturday\n";
            break;        
        }
    }
}

