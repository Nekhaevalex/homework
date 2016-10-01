//
//  Vector.h
//  Matrix
//
//  Created by Alex on 29/09/2016.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#ifndef Vector_h
#define Vector_h
#include <stdio.h>
#include <math.h>
#include "MatrixMath.h"

const double pi = 3.14159265359;

struct vector {
    double x;
    double y;
    double z;
};

struct base {
    struct vector e1;
    struct vector e2;
    struct vector e3;
};

double degree (double a) {
    return (a*180)/pi;
}

struct vector inRightOrto(double x, double y, double z) {
    struct vector a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

struct vector sum (struct vector a, struct vector b) {
    struct vector c;
    c.x = a.x+b.x;
    c.y = a.y+b.y;
    c.z = a.z+b.z;
    return c;
}

struct vector nmultiply (double b, struct vector a) {
    struct vector c;
    c.x=a.x*b;
    c.y=a.y*b;
    c.z=a.z*b;
    return c;
}

double module (struct vector a) {
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

double  ortoScalarProduct (struct vector a, struct vector b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double scalarProduct (struct vector a, struct vector b, double angle) {
    return module(a)*module(b)*cos(angle);
}

double angle (struct vector a, struct vector b) {
    return acos(ortoScalarProduct(a, b)/(module(a)*module(b)));
}

struct vector projection (struct vector a, struct vector b) {
    struct vector c;
    double up = ortoScalarProduct(b, a);
    double down = ortoScalarProduct(a, a);
    c = nmultiply(up/down, a);
    return c;
}

struct vector crossProduct (struct vector a, struct vector b) {
    struct vector c;
    c.x = a.y*b.z-a.z*b.y;
    c.y = -1*(a.x*b.z-a.z*b.x);
    c.z = a.x*b.y-a.y*b.x;
    return c;
}

struct base takeAsBase (struct vector e1, struct vector e2, struct vector e3) {
    struct base a;
    a.e1 = e1;
    a.e2 = e2;
    a.e3 = e3;
    return a;
}

struct vector inBase (struct vector a, struct base b) {
    struct vector c;
    //make matrix
    double** matrix = (double**)malloc(3*sizeof(double));
    for(int i = 0; i < 3; i++) {
        matrix[i] = (double *)malloc(3*sizeof(double));
    }
    //fill it with base
    matrix[0][0] = b.e1.x;
    matrix[1][0] = b.e1.y;
    matrix[2][0] = b.e1.z;
    
    matrix[0][1] = b.e2.x;
    matrix[1][1] = b.e2.y;
    matrix[2][1] = b.e2.z;
    
    matrix[0][2] = b.e3.x;
    matrix[1][2] = b.e3.y;
    matrix[2][2] = b.e3.z;
    
    //get det of matrix
    double d = det(matrix, 3);
    //replace 1st column with vector a and get det
    matrix[0][0] = a.x;
    matrix[1][0] = a.y;
    matrix[2][0] = a.z;
    double dx = det(matrix, 3);

    //replace 2nd column with vector a and get det
    matrix[0][0] = b.e1.x;
    matrix[1][0] = b.e1.y;
    matrix[2][0] = b.e1.z;
    
    matrix[0][1] = a.x;
    matrix[1][1] = a.y;
    matrix[2][1] = a.z;
    double dy = det(matrix, 3);
    //replace 3rd column with vector a and get det
    matrix[0][1] = b.e2.x;
    matrix[1][1] = b.e2.y;
    matrix[2][1] = b.e2.z;
    
    matrix[0][2] = a.x;
    matrix[1][2] = a.y;
    matrix[2][2] = a.z;
    double dz = det(matrix, 3);
    free(matrix);
    
    //return dx, dy, dz as vector
    c.x = dx/d;
    c.y = dy/d;
    c.z = dz/d;
    return c;
}

struct vector transformToBase (struct vector a, struct base fromBase, struct base toBase) {
    struct vector c;
    struct base old;
    //calculate a1, a2, a3 of toBase in fromBase
    old.e1 = inBase(fromBase.e1, toBase);
    old.e2 = inBase(fromBase.e2, toBase);
    old.e3 = inBase(fromBase.e3, toBase);
    //make matrix of a1..a9
    double** matrix = (double**)malloc(3*sizeof(double *));
    for(int i = 0; i < 3; i++) {
        matrix[i] = (double *)malloc(3*sizeof(double));
    }
    matrix[0][0] = old.e1.x;
    matrix[1][0] = old.e1.y;
    matrix[2][0] = old.e1.z;
    
    matrix[0][1] = old.e2.x;
    matrix[1][1] = old.e2.y;
    matrix[2][1] = old.e2.z;
    
    matrix[0][2] = old.e3.x;
    matrix[1][2] = old.e3.y;
    matrix[2][2] = old.e3.z;
    
    double** m1 = (double**)malloc(3*sizeof(double *));
    for(int i = 0; i < 3; i++) {
        m1[i] = (double *)malloc(1*sizeof(double));
    }
    double** m2 = (double**)malloc(3*sizeof(double *));
    for(int i = 0; i < 3; i++) {
        m2[i] = (double *)malloc(1*sizeof(double));
    }
    m1[0][0] = a.x;
    m1[1][0] = a.y;
    m1[2][0] = a.z;
    //solve V'=A*V
    multilpyWithMatrix(matrix, m1, 3, 3, 1, m2);
    //return V'
    c.x = m2[0][0];
    c.y = m2[1][0];
    c.z = m2[2][0];
    free(matrix);
    free(m1);
    free(m2);
    return c;
}


void printVector (const struct vector a) {
    printf("(%f; %f; %f)\n", a.x, a.y, a.z);
}

#endif /* Vector_h */
