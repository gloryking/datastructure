#include <stdio.h>

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main(){
    int a = 2;
    int b = 3;
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a = %d   ",a);
    printf("b = %d   ",b);

    // using pointer
    int c = 5;
    int d = 10;
    swap(&c, &d);
    printf("c = %d   ",c);
    printf("d = %d   ",d);

    return 0;
}