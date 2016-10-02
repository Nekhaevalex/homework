//
//  main.c
//  TechnoTrack
//
//  Created by Alex on 19/09/2016.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//
#include <stdio.h>
#include <math.h>
const int INF_ROOTS = -1;
const double EPS = 1e-6;

int LinearEquation (double b, double c, double* x1) {
    *x1 = (-c/b);
    return *x1;
}

int SquareEquation1 (double a, double c, double* x1) {
    if (c<0) {
        *x1 = sqrt(-c/a);
        return *x1;
    }
    else {
        return 0;
    }
}

int SquareEquation2 (double a, double c, double* x2) {
    if (c<0) {
        *x2 = -sqrt(-c/a);
        return *x2;
    }
    else {
        return 0;
    }
}

int nonCEquation1 (double a, double b, double* x1) {
    *x1 = 0;
    return *x1;
}

int nonCEquation2 (double a, double b, double* x2) {
    *x2 = -b;
    return *x2;
}

int onlyBEquation (double* x1) {
    *x1 = 0;
    return *x1;
}

int onlyCEquation (double* x1) {
    *x1 = 0;
    return *x1;
}

int SqEquation(double a, double b, double c, double* x1, double* x2) {
    if (a == 0) {
        *x1 = LinearEquation (b, c, x1);
    }
    else if (b == 0) {
        *x1 = SquareEquation1(a, c, x1);
        *x2 = SquareEquation2(a, c, x2);
    }
    else if (c == 0) {
        *x1 = nonCEquation1(a, b, x1);
        *x2 = nonCEquation2(a, b, x2);
    }
    else {
        double d = b*b-4*a*c;
        if (d == 0){
            *x1 = (-b)/(2*a);
            *x2 = *x1;
        }
        else {
            *x1 = (-b+sqrt(d))/(2*a);
            *x2 = (-b-sqrt(d))/(2*a);
        }
    }
    return 0;
}

int main() {
    printf("#SqEquation v1.0 © Ded, 2016\n");
    printf("#Enter a b c:\n");
    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    double x1 = 0, x2 = 0;
    int nRoots = SqEquation(a, b, c, &x1, &x2);
    switch (nRoots) {
        case 2:
            printf("x1 = %lg\n", x1);
            printf("x2 = %lg\n", x2);
            break;
        case 1:
            printf("x1 = %lg\n", x1);
            break;
        case 0:
            printf(":((((((\n");
            break;
        case INF_ROOTS:
            printf("XD\n");
            break;
        default:
            return 1;
            break;
    }
    return 0;
}

