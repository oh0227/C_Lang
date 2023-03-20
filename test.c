#include <stdio.h>

int zer = 0, one = 0, two = 0, thr = 0, fou = 0, fiv = 0, six = 0, sev = 0, eig = 0, nin = 0;

void check(int v){
    switch(v) {
    case 0:
        zer++;
        break;
    case 1:
        one++;
        break;
    case 2:
        two++;
        break;
    case 3:
        thr++;
        break;
    case 4:
        fou++;
        break;
    case 5:
        fiv++;
        break;
    case 6:
        six++;
        break;
    case 7:
        sev++;
        break;
    case 8:
        eig++;
        break;
    case 9:
        nin++;
        break;
    default:
        printf("???");
        break;
    }
}

int main(void){

    int a, b, c, v, total;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    total = a*b*c;
    
    if(1000000 <= total && 10000000 > total){
        for(int i = 1; i <= 7; i++){
            v = total / (10^(7-i));
            total = total % (10^(7-i));
            check(v);
        }
    }
    else if(10000000 <= total && 100000000 > total){
        for(int i = 1; i <= 8; i++){
            v = total / (10^(8-i));
            printf("v = %d total is %d\n", v, total);
            total = total % (10^(8-i));
            check(v);
        }
    }
    else if(100000000 <= total && 1000000000 > total){
        for(int i = 1; i <= 9; i++){
            v = total / (10^(9-i));
            total = total % (10^(9-i));
            check(v);
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",zer,one,two,thr,fou,fiv,six,sev,eig,nin);
    return 0;
}

