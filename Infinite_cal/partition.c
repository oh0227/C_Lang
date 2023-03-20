#include "Infinite_cal.h"


int partition(int* a, int left, int right)
{
    int pivot;
    int leftPoint, rightPoint, temp;
    pivot = a[left];
    leftPoint = left;
    rightPoint = right + 1;

    while(rightPoint > leftPoint)
    {
        while(a[leftPoint] <= pivot && leftPoint <= right)
            leftPoint ++;
        while(a[rightPoint] > pivot)
            rightPoint --;
        temp = a[leftPoint]; 
        a[leftPoint] = a[rightPoint]; 
        a[rightPoint] = temp;
    }
    temp = a[left];
    a[left] = a[rightPoint];
    a[rightPoint] = temp;
    return rightPoint;
}

int main(void){
    // char* s = "1+34";
    // char a = partition(s, 1,2);
    // printf("%c\n",a);
    int a[] = {1,2,3,4,5,6,7,8};
    printf("%d",partition(a, 1,5));

    return 0;
}