#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("event_log_1.txt","r",stdin);
    freopen("all_time.txt","w",stdout);
    string previous="qwertyuiopasdfghjklzxcvbnmqwertyuioasdfghjkcxcfy7trdcvhuytfcvbhjuytfcvbjuytfcvbhytf";
    string now;
    while(getline(cin,now)){
        //cout<<now.size()<<"        "<<previous.size()<<"     "<<endl;
        if(now.size()<22||previous.size()<22||now[23]=='r')
            continue;
        string t1=now.substr(1,20),t2=previous.substr(1,20);
        //cout<<t1<<endl<<t2;
        if(t1!=t2){
            for(int i=1;i<21;i++)
                cout<<now[i];
            cout<<endl;
            previous=now;
        }  
    }
}
