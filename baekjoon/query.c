#include <stdio.h>

int check(int a){
    if(a == 1) return 1;
    if(a == 2) return 1;
    else if(a%2 == 0) return check(a/2);
    else return 0; 
}

int main(void){
    int q, a;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &a);
        printf("%d\n", check(a));
    }
    return 0;
}