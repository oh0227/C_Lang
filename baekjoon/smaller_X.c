#include <stdio.h>

int main(void){
    int n, x, v;
    int cnt = 0;
    scanf("%d %d", &n, &x);

    for(int i = 0; i < n; i++){
        scanf("%d ", &v);
        if(v < x){
           printf("%d ",v);
        }
    }
    return 0;
}