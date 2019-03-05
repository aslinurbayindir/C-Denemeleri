#include<stdio.h>
#include<stdlib.h>

int main() {

    int a[5] = {1,12,3,4,5};

    for (int i=0; i<5; i++){
         printf("%d -",a[i]);
    }
    printf("\n");

    int *b = (int *)malloc(sizeof(int)*5);
    b[2]=5;
    b[4]=8;
    b[0]=14;
    *(b+1)=17;

    for (int i=0; i<5; i++){
         printf("%d -",b[i]);
    }
    return 0;
