#include <stdio.h>

int main(void){
    int a[30] = {0};
    int n;
    int m = 30;
    while(m--){
        scanf("%d",&n);
        a[n-1]++;
    }
    for(int i = 0; i < 30; i++){
        if(a[i] == 0)
            printf("%d\n",i+1);
    }
    return 0;
}