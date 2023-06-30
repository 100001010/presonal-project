// p_1_3, random test data
#include <bits/stdc++.h>
using namespace std;
#define N 50010
int a[N];
int main() {
	char infile[30]="p_1_3_0.in";
	srand(51);
for (int ii=1;ii<6;ii++) {
    infile[6]='0'+ii;
	freopen(infile,"w",stdout);
	int n=50000-rand()%1000;
	int m=1e9 -rand()%10000000;
	set<int> S;
	for (int i=0;i<n;i++)
        S.insert(rand()%(m-100)+1);
	n=S.size();
	printf("%d %d\n",n, m);
	auto it=S.begin();
	printf("%d",*it);
	it++;
	while (it!=S.end()) {
        printf(" %d",*it);
        it++;
	}
	printf("\n");
}
    return 0;
}
