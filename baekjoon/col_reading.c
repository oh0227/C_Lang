#include <stdio.h>
#include <string.h>


int max(char s[][]){
    int a;
    a = strlen(s[0]);
    for(int i = 0; i < 4; i++){
        if(s[i] < s[i+1]) a = strlen(s[i+1]);
    }
    return a;
}

int main(void)
{
    char s[5][16];

    for(int i = 0; i < 5; i++){
        scanf("%s", &s[i]);
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < max(s); j++){
            if(s[j][i] == " ") printf("");
            printf("%c", s[j][i]);
        }
    }

    return 0;
}