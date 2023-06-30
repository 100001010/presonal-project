// p_1_3, lower_bound
#include <bits/stdc++.h>
using namespace std;
#define N 50010
typedef long long LL;
LL p[N];

// find the cut in (left,right), and then recursively
LL cut(int left, int right) {
    if (right-left<=1) return 0;
    LL k=(p[right]+p[left])/2;

    int m=lower_bound(p+left, p+right,k)-p;
    if (p[m-1]-p[left] >= p[right]-p[m])
        m--;
    return p[right]-p[left] + cut(left, m) + cut(m, right);
}

int main() {
	int i, n, l;
    scanf("%d%d", &n, &l);
    p[0]=0; p[n+1]=l;
    for (i=1; i<=n; i++) scanf("%lld", &p[i]);
    for (i=0; i<=n;i++) assert(p[i]<p[i+1]);
    printf("%lld\n",cut(0, n+1));
	return 0;
}
