// max score of <=n-queens
#include<bits/stdc++.h>
using namespace std;
#define N 20
int n, ans=0;
int p[N], best[N];   // column indexes of previous rows
int score[N][N]={0};

// k is current row, s is current score
void nqr(int k, int s) {
    if (k>=n) return; // no more rows, successful
    bool valid[N];
    for (int i=0;i<=n;i++) valid[i]=true;
    // mark positions attacked by (j,p[j])
    for (int j=0; j<k; j++) {
        if (p[j]>=n) continue; // empty row
        valid[p[j]]=false;
        int i=k-j+p[j];
        if (i<n) valid[i]=false;
        i=p[j]-(k-j);
        if (i>=0) valid[i]=false;
    }
    for (int i=0;i<=n;i++) { // try each column
        if (valid[i]) {
            p[k]=i;
            int t=s+score[k][i];
            if (t>ans) {
                ans=t;
                for (int x=0;x<n;x++)
                    best[x]=(x<=k)?p[x]:-1;
            }
            nqr(k+1,t);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++)
        scanf("%d", &score[i][j]);
    nqr(0,0);
    printf("%d\n",ans);
    fprintf(stderr,"ans=%d\n",ans);
    int sum=0,null_row=0;
    for (int i=0;i<n;i++) {
        fprintf(stderr,"%d ",best[i]);
        if (best[i]<n)
            sum += score[i][best[i]];
        else null_row++;
    }
    fprintf(stderr," sol sum=%d, null row= %d\n",sum,null_row);
    return 0;

}
