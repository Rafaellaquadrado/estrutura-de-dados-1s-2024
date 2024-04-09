#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int a = 2;
    int b = a;

    printf("a = %d \t b = %d\n", a, b);
    printf("&a = %p \t b %p\n", &a, &b);


    exit(0);
}
