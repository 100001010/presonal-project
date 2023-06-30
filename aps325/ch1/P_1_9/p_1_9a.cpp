#include<bits/stdc++.h>
using namespace std;

int nq(int n) {
    int p[14], total=0, cnt=0;;
    for (int i=0;i<n;i++) p[i]=i; //first permutation
    do {
        cnt++;
        // check valid
        bool valid=true;
        for (int i=0; i<n; i++) for (int j=i+1;j<n;j++)
            if (abs(p[i]-p[j])==j-i) { // one the same diagonal
                valid=false;
                break;
            }
        if (valid) total++;
    } while (next_permutation(p, p+n)); // until no-next
    fprintf(stderr,"n=%d, n!=%d\n", n, cnt);
    return total;
}

int main() {
    for (int i=1;i<12;i++) {
        printf("%d ",nq(i));
    }
    return 0;

}
