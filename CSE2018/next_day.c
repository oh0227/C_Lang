/* Compute the next day. */
#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

typedef     enum day    day;

day find_next_day(day d)
{
    day next_day;

    switch (d){
    case sun:
        next_day = mon;
        break;
    case mon:
        next_day = tue;
        break;
    case tue:
        next_day = wed;
        break;
    case wed:
        next_day = thu;
        break;
    case thu:
        next_day = fri;
        break;
    case fri:
        next_day = sat;
        break;
    case sat:
        next_day = sun;
        break;
    }
    return next_day;
}

int main(void){
    int a = (int)(find_next_day(sun));
    printf("%d", a);
    return 0;
}