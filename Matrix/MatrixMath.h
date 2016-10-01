//
//  MatrixMath.h
//  Matrix
//
//  Created by Alex on 16.09.16.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#ifndef MatrixMath_h
#define MatrixMath_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initMatrix(double **matrix, int n) {
    matrix = (double**)malloc(n*sizeof(double *));
    for(int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n*sizeof(double));
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix (double **matrix, int n, int m) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void getMatrix(double **matrix, double **p,int i,int j,int m) {
    int ki,kj,di,dj;
    di=0;
    for(ki=0;ki<m-1;ki++) { // проверка индекса строки
        if (ki==i)  di=1;
        dj=0;
        for(kj=0;kj<m-1;kj++) { // проверка индекса столбца
            if (kj==j)  dj=1;
            p[ki][kj]=matrix[ki+di][kj+dj];
        }
    }
}

double det (double** matrix, int m) {
    int i, j, d, k, n;
    double **p = (double**)malloc(m*sizeof(int *));
    for(int i = 0; i < m; i++) {
        p[i] = (double *)malloc(m*sizeof(double));
    }
    j = 0;
    d = 0;
    k=1;
    n=m-1;
    if (m<1) {
        printf("Error: Incompatible function");
    }
    if (m==1) {
        d = matrix[0][0];
        return d;
    }
    if (m==2) {
        d = matrix[0][0]*matrix[1][1]-(matrix[1][0]*matrix[0][1]);
        return d;
    }
    if (m>2){
        for (i=0;i<m;i++) {
            getMatrix(matrix,p,i,0,m);
            d = d + k * matrix[i][0] * det(p,n);
            k=-k;
        }
    }
    return(d);
}

void transposition (double** matrix, int** result, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

void multilpyWithNumber (double** matrix, int a, int m, int n) {
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; i++) {
            matrix[i][j] = matrix[i][j]*a;
        }
    }
}

void madd (double** matrix1, double** matrix2, const int m, const int n) {
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

void multilpyWithMatrix (double** matrix1, double** matrix2, int n, int m, int p, double** matrix3) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < p; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            matrix3[row][col] = 0;
            for (int inner = 0; inner < m; inner++) {
                matrix3[row][col] += matrix1[row][inner] * matrix2[inner][col];
            }
        }
    }
}

void inputMatrix (double** matrix, const int n, const int m) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("a[%d][%d]:=", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

#endif /* MatrixMath_h */
