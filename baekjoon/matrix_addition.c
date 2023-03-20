#include <stdio.h>

int main(void){
    int n, m, b;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d ",&a[i][j]);


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d ",&b);
            a[i][j] += b;
        }
    }

            
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;

}