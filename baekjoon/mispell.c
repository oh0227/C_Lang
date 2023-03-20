#include <stdio.h>

int main(void){
    int t, a;
    char c[81]; 
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %s", &a, &c);
        for(int j = a-1; j < 80; j++){
            c[j] = c[j+1];
        }
        printf("%s\n", &c);
    }
    return 0;
}