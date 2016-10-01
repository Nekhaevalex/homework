//
//  main.c
//  Matrix
//
//  Created by Alex on 16.09.16.
//  Copyright © 2016 JL Computer Inc. All rights reserved.
//

#include <stdio.h>
#include <Math.h>
#include "MatrixMath.h"
#include "Vector.h"

int main() {
    struct vector a;
    struct vector b;
    a = inRightOrto(1, 0, 0);
    b = inRightOrto(1, 2, 0);
    double c = scalarProduct(a, a, 0);
    printf ("%f", c);
    return 0;
}
