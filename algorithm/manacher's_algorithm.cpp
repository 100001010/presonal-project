#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    string ta="mamamttmamh";
    vector <int> v(2*ta.size()+1);
    vector <int> t(2*ta.size()+1);
    string nta="%";
    for(char i:ta){
        nta+=i;
        nta+='#';
    }
    nta.erase(nta.end()-1);
    nta+='&';
    cout<<nta;
    int c=0,r=0;
    for(int i=1;i<2*ta.size()+2;i++){
        int b,e;
        if(c+r>i){
            b=i-min(c+r-i,v[c-(i-c)])-1;
            e=i+min(c+r-i,v[c-(i-c)])+1;
            v[i]=min(c+r-i,v[c-(i-c)]);
        }else{
            b=i-1;
            e=i+1;
            
        }
        
        while(nta[b]==nta[e]){
            b--;e++;
            v[i]++;
        }
        if(i+v[i]>c+r){
            c=i;
            r=v[i];

        }
    }
    cout<<endl;
    for(int i:v)
        cout<<i<<"";
        cout<<endl;
    
}




