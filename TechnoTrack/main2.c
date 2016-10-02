//
//  main2.c
//  TechnoTrack
//
//  Created by Alex on 26/09/2016.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int SolveNotSquare(int degree, const double coeff[], double roots[]) { //const double – защита переменной от изменения функцией
    if (degree >= 5) {
        degree = 1;
    }
    return 0;
}
double* SolveSq (const int degree, const double coeff[]) {
    static double roots[100];
    roots[1] = 0;
    return roots;
}
int main() {
    double coeff[] = {};
    double* roots = SolveSq(2, coeff);
    double* roots2 = SolveSq(1, coeff);
    return 0;
}
