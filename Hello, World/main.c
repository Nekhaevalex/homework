//
//  main.c
//  Homework
//
//  Created by Alex on 19/09/2016.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x;
    int y;
};

void searchMax() {
    int N;
    int i = 0;
    printf("Max\n------------------------\n");
    printf("Input array size: ");
    scanf("%d", &N);
    int* array = malloc(N*sizeof(int));
    printf("Input array elements: ");
    for (i = 0; i<N; i++) {
        scanf("%d", &array[i]);
    }
    int max = array[0];
    for (i = 1; i<N; i++) {
        if (array[i]>max) {
            max = array[i];
        }
    }
    printf("Max: %d\n", max);
    free(array);
}

void fibonnachiI() {
    printf ("Числа Фибонначи I\n------------------------\n");
    int i;
    int j;
    scanf("%d", &i);
    int result = 0;
    int a = 1;
    printf("%d ", a);
    int b = 1;
    printf("%d ", b);
    int c;
    if (i == 0 || i == 1) {
        result = i;
    }
    else {
        for (j = 3; j<=i; j++) {
            printf("%d ", a+b);
            result = a+b;
            c = b;
            b = a+b;
            a = c;
        }
    }
    printf ("\nResult: %d", result);
}

int factorial (int n) {
    return (n<2) ? 1 : n * factorial(n-1);
}

int sochetanie (int n, int k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}

void binominal (int n) {
    printf ("(1+x)^n = 1*x0");
    int i;
    int c;
    for (i = 1; i<n; i++) {
        c = sochetanie(n, i);
        printf("+%d*x%d", c, i);
    }
    printf ("\n");
}

int fibonnachiII(int a) {
    if (a <= 2) {
        return 1;
    }
    else {
        return fibonnachiII(a-1) + fibonnachiII(a-2);
    }
}

int prime(int n){
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}

void randomArea (){
    printf ("Input amount of points, please (we can't compleate calculation without it): ");
    int n = 0;
    scanf ("%d", &n);
    struct point* points = malloc(n*2*sizeof(struct point));
    int i=0;
    int j=0;
    // input array
    for (i = 0; i<n; i++) {
        printf("%d) X%d;Y%d: ", i+1, i+1, i+1);
        scanf ("%d %d", &points[i].x, &points[i].y);
    }
    int width = 0, height = 0;
    for (i = 0; i<n; i++) {
        if (points[i].x>width) {
            width = points[i].x;
        }
        if (points[i].y>height) {
            height = points[i].y;
        }
    }
    int **map = (int**)malloc((height+2)*sizeof(int *));
    for(int i = 0; i <= height+2; i++) {
        map[i] = (int *)malloc((width+2)*sizeof(int));
    }
    for (i = 0; i<=height+1; i++) {
        for (j = 0; j<=width+1; j++) {
            map[i][j] = 0;
        }
    }
    for (i = 0; i<n; i++) {
        map[points[i].x][points[i].y] = 1;
    }
    //printing matrix
    for (i = 0; i<=height; i++) {
        for (j = 0; j<=width; j++) {
            printf("%d", map[j][i]);
        }
        printf ("\n");
    }
    int area = 0;
    //let's calculate area with defined integral)))))
    //Modifying figure
    for (i = 0; i<=width; i++) {
        for (j = 0; j<=height; j++) {
            if (map[i][j] == 1) {
                if (map[i+1][j] == 1) {
                    map[i+1][j] = 0;
                }
                else {
                    map[i+1][j] = 1;
                }
            }
        }
    }
    printf("\n");
    for (i = 0; i<=height; i++) {
        for (j = 0; j<=width; j++) {
            printf("%d", map[j][i]);
        }
        printf ("\n");
    }
    //Calculating 1-column area
    int state = 0;
    for (i = 0; i<=height; i++) {
        for (j = 0; j<=width; j++) {
            state = abs(state-map[i][j]);
            area = area + state*(1);
        }
    }
    printf ("Area: %d\n", area);
    free (map);
    free (points);
}

void Josef() {
    int M = 0;
    int N = 0;
    printf ("Input amount of words: ");
    scanf("%d", &M);
    printf ("Input amount of people: ");
    scanf ("%d", &N);
}

int main() {
    int w = 1;
    char empty;
    while (w == 1) {
        printf("Домашнее задание №3\nВведите номер задачи для вывода\n 1) Max\n 2) Числа Фибонначи I\n 3) Числа Фибонначи II\n 4) Биноминальные коэффициенты\n 5) Простые числа\n 6) Площадь фигуры\n 7) Задача Иосифа\n 0) Выход\n");
        int selected;
        printf("Выбрано: ");
        scanf("%d", &selected);
        if (selected == 1) {
            searchMax();
            scanf("%c", &empty);
        }
        if (selected == 2) {
            fibonnachiI();
            scanf("%c", &empty);
        }
        if (selected == 3) {
            printf ("Числа Фибонначи II\n------------------------\n");
            int a;
            scanf ("%d", &a);
            int b = fibonnachiII(a);
            printf("%d", b);
            scanf("%c", &empty);
        }
        if (selected == 4) {
            int a;
            printf ("Введите степень (1+x) ");
            scanf("%d", &a);
            binominal(a);
        }
        if (selected == 5) {
            printf("Простые числа\n---------------------------\n");
            int c;
            scanf ("%d", &c);
            int answer = prime(c);
            if (answer == 1) {
                printf("%d - простое число\n", c);
            }
            else if (answer == 0) {
                printf("%d - не простое число\n", c);
            }
        }
        if (selected == 6) {
            randomArea();
        }
        
        if (selected == 7) {
            Josef();
        }
        if (selected == 0) {
            w = 0;
        }
    }
    return 0;
}

