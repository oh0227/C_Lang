#include <limits.h>

int pack(char a, char b, char c, char d)
{
    int p = a;

    p = (p << CHAR_BIT) | b;
    p = (p << CHAR_BIT) | c;
    p = (p << CHAR_BIT) | d;
    return p;
}

int unpack(int p, int k)
{
    int n = k * CHAR_BIT;
    unsigned mask = 255;
    mask <<= n;
    return ((p & mask) >> n);
}

void bit_print(int a){
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n-1);

    for (i = 1; i <= n; i++){
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;
        if(i % CHAR_BIT == 0 && i < n)
        putchar(' ');
    }
}

int main(void){
    printf("abcd = ");
    bit_print(pack('a', 'b', 'c', 'd'));
    int a = pack('a', 'b', 'c', 'd');
    putchar('\n');
    printf("a = ");
    bit_print(unpack(a, 0));
    putchar('\n');
}