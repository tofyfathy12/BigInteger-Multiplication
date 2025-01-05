#include <stdio.h>
#include <stdlib.h>


int main()
{
    // int num1 = 1;
    // char num2 = 2;
    // double num3 = 3;
    // float num4 = 4;
    // long int num5 = 5;
    // unsigned int num6 = 6;
    // unsigned long int num7 = 7;
    // int *p1 = &num1;
    // char *p2 = &num2;
    // double *p3 = &num3;
    // float *p4 = &num4;
    // long int *p5 = &num5;
    // unsigned int *p6 = &num6;
    // unsigned long int *p7 = &num7;
    // printf("num1 size: %d\n", sizeof(num1));
    // printf("num2 size: %d\n", sizeof(num2));
    // printf("num3 size: %d\n", sizeof(num3));
    // printf("num4 size: %d\n", sizeof(num4));
    // printf("num5 size: %d\n", sizeof(num5));
    // printf("num6 size: %d\n", sizeof(num6));
    // printf("num7 size: %d\n", sizeof(num7));
    // printf("p1 size: %d\n", sizeof(p1));
    // printf("p2 size: %d\n", sizeof(p2));
    // printf("p3 size: %d\n", sizeof(p3));
    // printf("p4 size: %d\n", sizeof(p4));
    // printf("p5 size: %d\n", sizeof(p5));
    // printf("p6 size: %d\n", sizeof(p6));
    // printf("p7 size: %d\n", sizeof(p7));
    // printf("p1 address in decimal : %d\n", p1);
    // printf("p1 address in hexadecimal : %p\n", p1);
    char x[100] = "Hello world";
    printf("%s\n", x);
    free(x);

}