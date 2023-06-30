#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,i,n;
	char infile[30]="q_1_10_0.in";
	srand(5817);

for (i=1;i<16;i++) {
    sprintf(infile+7,"%02d.in",i);;
	freopen(infile,"w",stdout);
	if (i<6) n=i+5;
	else n=10-rand()%3;
	printf("%d\n",n);
	for (int j=0;j<n;j++) for (t=0;t<n;t++) {
        printf("%d%c", rand()%100+1, " \n"[t==n-1]);
	}
}
	return 0;
}
