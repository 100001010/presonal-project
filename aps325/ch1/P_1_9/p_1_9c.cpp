// number of n-queens, recursion, better
#include<bits/stdc++.h>
using namespace std;
long long cnt=0; // count num of recursion

// k is current row, p[] are column indexes of previous rows
int nqr(int n, int k, int p[]) {
    cnt++;
    if (k>=n) return 1; // no more rows, successful
    int total=0;
    bool valid[n];
    for (int i=0;i<n;i++) valid[i]=true;
    // mark positions attacked by (j,p[j])
    for (int j=0; j<k; j++) {
        valid[p[j]]=false;
        int i=k-j+p[j];
        if (i<n) valid[i]=false;
        i=p[j]-(k-j);
        if (i>=0) valid[i]=false;
    }
    for (int i=0;i<n;i++) { // try each column
        if (valid[i]) {
            p[k]=i;
            total+=nqr(n,k+1,p);
        }
    }
    return total;
}

int main() {
    int p[15];
    for (int i=1;i<12;i++) {
        cnt=0;
        printf("%d ",nqr(i,0,p));
        fprintf(stderr,"n=%d, num of recursions=%lld\n",i,cnt);
    }
    return 0;

}
