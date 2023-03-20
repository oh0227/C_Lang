#include <stdio.h>
#include <string.h>

int main(void){
    char s[101];
    scanf("%s", &s);
    for(int i = 0; i < strlen(s); i++){
        if (s[i] > 96)
            s[i] = s[i] -'a' + 'A';
        else 
            s[i] = s[i] - 'A' + 'a';
    }
    printf("%s",s);
    return 0;
}