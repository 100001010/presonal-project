#include<iostream>
using namespace std;
int f(int a){
	if(a==0)
		return 0;
	int c=f(a/2);
	cout<<a%2;
	if(a%2==1)
		c++;
	return c;
	
}
int main(){
  int a;
  while(cin>>a,a!=0){
  	cout<<"The parity of ";
  	int c=f(a);
  	cout<<" is "<<c<<" (mod 2).\n";
  }
  return 0;
}
