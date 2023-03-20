#include <stdio.h>
#include <math.h>

int main(void)
{
    int c;

    for(c = 1; c <= 100; c++){
        printf("root %d = %lf\n", c, sqrt((double)c));
    }

    return 0;
}