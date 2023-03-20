#include <stdio.h>

int main(void){
    int a[8] = {0};
    int n;
    int e=0, b=0, c=0;
    for(int i = 0; i < 8; i++){
        scanf("%d ", &n);
        a[i] = n;
    }
    for(int j = 0; j < 7; j++){
        if(a[j+1] - a[j] == 1)
            e++;
        else if(a[j] - a[j+1] == 1)
            b++;
        else
            c++;
    }
    if(e==7) printf("ascending");  
    else if(b==7) printf("descending");
    else printf("mixed");
    return 0;
}