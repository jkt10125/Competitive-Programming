#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a = b - a;
        if(a < 0) {
            printf("-1\n");
            continue;
        }
        a *= 2;
        a++;
        printf("%d\n", a/c+1); 
    }
}