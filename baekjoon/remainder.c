#include <stdio.h>

int main(void){
    int a[43] = {0};
    int n, cnt = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d",&n);
        if(a[n%42] == 0){
            a[n%42]++;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;

}