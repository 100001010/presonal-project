// subset product = 1 mod P, using loop
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans=0;
    long long P=10009, A[26];
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", &A[i]);
    for (int s=1; s< (1<<n); s++) {
        long long prod=1;
        for (int j=0;j<n;j++) {
            if (s & (1<<j))
                prod = (prod*A[j])%P;
        }
        if (prod==1) ans++;
    }
    printf("%d\n", ans);
}
