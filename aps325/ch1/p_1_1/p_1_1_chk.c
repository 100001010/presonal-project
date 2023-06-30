#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int f(void);
int g(void);
int eval(){
    int val;
    char c;
    if (scanf("%d",&val) == 1) {
        assert(abs(val)<=1000);
        return val;
    }
    scanf("%c", &c);
    if (c == 'f') return f();
    if (c == 'g') return g();
    fprintf(stderr,"error");
}

int f() {
    int x = eval();
    assert(abs(x)<=100000000);
    return 2*x - 1;
}
int g() {
    int x,y;
    x = eval();
    y = eval();
    assert(abs(x)<=100000000);
    assert(abs(y)<=100000000);
    return x + 2*y -3;

}

int main() {
    printf("%d\n",eval());
    char c,c2;
    if (scanf("%c",&c)!=EOF) {
        if (c!='\n' || scanf("%c",&c2)!=EOF)
            fprintf(stderr,"excessive input=%x\n",c);
    }
    return 0;
}
