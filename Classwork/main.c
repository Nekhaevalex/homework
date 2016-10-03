//
//  main.c
//  Classwork
//
//  Created by Alex on 19/09/2016.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void plusPlus(int* pointer, int n) {
    int i = 0;// for old compilers
    for (i = 0; i<n; i++) {
        *(pointer+i) += 1;
    }
}

void demo() {
    int b;
    b = 5;
    printf("b: %d: %d\n", b, b);
    
    int* c = &b;
    printf ("c = %d\n*c = %d\n", c, *c);
    *c = 7;
    printf ("b = %d *c = %d\n", b, *c);
    int** d = &c;
    printf ("Value = %d", **d);
}

void pointerMath() {
    int arr[10];
    int i;
    for (i = 0; i<10; i++) {
        arr[i] = i;
        printf("arr[%d] = %d Addr = %d\n", i, arr[i], &arr[i]);
    }
    printf("Value0 = %d\n", arr);
}

int main() {
    pointerMath();
    int n = 0;
    int i = 0;
    scanf ("%d", &n);
    int* array = malloc(n*sizeof(int));
    for (i = 0; i<n; i++) {
        *(array+i) = 0;
    }
    plusPlus(array, n);
    for (int i = 0; i<n; i++) {
        printf("n == %d\n", *(array+i));
    }
    return 0;
}
