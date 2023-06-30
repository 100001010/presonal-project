#include<stdio.h>
#include <stdlib.h>
#define R 1000
int ifneg,prob,iffirst;
int count,dep;

int ran() {
    if (ifneg==0) return rand()%10;
    return (rand()%(2*R+1)-R);
}

void f(void);
void g(void);
void h(void);
void one(){
    if (iffirst==0) printf(" ");
    if (dep>12 || (iffirst==0 && count>2 && rand()%100<prob+count/2)) {
        printf("%d",ran());
        return;
    }
    iffirst=0;
    count++;
    int x=rand()%5;
    dep++;
    if (x>3 && count>2) f();
    else g();
    dep--;
    return;
}

void f() {
    printf("f");
    one();
}
void g() {
    printf("g");
    one();
    one();
}

int main() {
	int t,i,n;
	char infile[30]="p_1_1_0.in";
	srand(5810);
for (i=1;i<6;i++) {
    infile[6]=i+'0';
	freopen(infile,"w",stdout);
	ifneg=1;
	iffirst=1;
	prob=50-i*5;
	count=dep=0;
	one();
	printf("\n");
	//fprintf(stderr,"pr=%d, num func=%d\n",prob,count);
}

	return 0;
}
