#include <stdio.h>
#include <stdlib.h>
#include "int_vect.h"
#include "matrix.h"

int main(int argc, char** argv) {
    int arr[6] = {1, 2, 3, 4};
    int arr2[6] = {7, 8, 9, 10};

    MATRIX matrix = matrix_init_arr(arr, 2, 2);
    MATRIX matrix2 = matrix_init_arr(arr2, 2, 2);
    MATRIX matrix3 = matrix_math(matrix_init_scalar, matrix, matrix2);
    matrix_print(matrix);
    matrix_print(matrix2);
    matrix_print(matrix3);

    matrix_destroy(&matrix);
    matrix_destroy(&matrix2);
    matrix_destroy(&matrix3);
    return 0;
}
