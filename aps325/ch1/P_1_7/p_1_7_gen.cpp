#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,i,n;
	char infile[30]="p_1_7_0.in";
	srand(5817);

for (i=1;i<6;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	n=2*i+15;
	printf("%d\n",n);
	for (t=0;t<n;t++) {
        printf("%d%c", rand()%10000+1, " \n"[t==n-1]);
	}

}
	return 0;
}
