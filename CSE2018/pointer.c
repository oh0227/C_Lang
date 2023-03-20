#include <stdio.h>

int a(int);
int b(int);
int c(int);
int (*p[3])(int) = {a,b,c}; // 함수 포인터 배열을 만들어 주는 주소 저장

void main(void){
    int x,y,z,i;
    printf("\n메뉴\n1. 제곱\n");
    printf("2. 3제곱\n");
    printf("3. 4제곱\n");
    printf("원하는 작동을 선택하시오\n");
    scanf("%d", &i);

    z = p[i-1](4);

    printf("%d\n", z);
}

int a