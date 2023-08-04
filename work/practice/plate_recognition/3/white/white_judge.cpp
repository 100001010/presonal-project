#include<iostream>
#include<string>
#include<set>
#include <algorithm>
using namespace std;
int a(){
    int ar;
}
int main(){
    freopen("all_license.txt","r",stdin);
    freopen("no_in_white_array.txt","w",stdout);
    string s[35]={"AGU3659","ARE1316","BEE7158","0685GZ","BBA1339","9576DF","BPM3215","AGU1550","RS8478","BBE2770","BBM9626","AKK8125","DH2993","ANV7156","2028H9","9678J7","AAL3928","AWY7383","BJW9155","ATL6867","5026QM","BAZ0697","AKK6720","8B7839","AJF8800","AAD7379","0815L3","1168ER","ATA1651","APN7596","ANY3599","1803H9","ATM1232","3139WE","BFM1090"};
    string targat;
    a
    set <string> se;
    while(getline(cin,targat)){
        bool find=0;
        for(string i:s){
            if(i==targat){
                find=1;
                break;
            }
        }
        if(!find)
            se.insert(targat);
    }
    i=0;
    for(string i:se){
        cout<<i<<endl;
    }
}