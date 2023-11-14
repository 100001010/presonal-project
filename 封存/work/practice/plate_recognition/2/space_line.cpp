#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("event_log_2_channel1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    string s;
    long int total,next_total=0;
    while(getline(cin,s)){
        
        total=(s[13]*10+s[14])*3600+(s[16]*10+s[17])*60+(s[19]*10+s[20]);

        if(total-next_total>9||total-next_total<0)
            cout<<endl;
        cout<<endl;
        cout<<s;
        next_total=total;
    }
}