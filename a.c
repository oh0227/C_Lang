#include <stdio.h>

int str2int(char set[]){
    if(set == " ")
        return 0;
    else
        return int(set[0]) + str2int(set[1:]);
        
}

int main(void){

    int n;
    n = str2int("13531");

    printf("%d", n);
    return 0;
}

