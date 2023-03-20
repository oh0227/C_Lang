#include <stdio.h>

int main(void) {
    int m = 0, v = 0, cnt = 0;
    int i,j;
    int a[9];
    for(i = 0; i < 9; i++){
        scanf("%d", &m);
        a[i] = m;
    }
    
    v = a[0];
    for(j = 0; j < 8; j++){
        if(v < a[j+1]){
            v = a[j+1];
            cnt = j;
        }
    }
    if(v == a[0])
        printf("%d\n%d", v, cnt+1);
    else
        printf("%d\n%d", v, cnt+2);
    return 0;
}