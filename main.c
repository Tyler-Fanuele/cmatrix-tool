#include <stdio.h>
#include <stdlib.h>
#include "int_vect.h"
#include "matrix.h"

int main(int argc, char** argv) {
    int arr[4] = {1, 2, 3, 4};
    int arr2[4] = {2, 2, 2, 2};

    MATRIX matrix = matrix_init_arr(arr, 2, 2);
    MATRIX matrix2 = matrix_init_arr(arr2, 2, 2);
    MATRIX matrix3 = matrix_add(matrix, matrix2);
    matrix_print(matrix);
    matrix_print(matrix2);
    matrix_print(matrix3);

    matrix_destroy(&matrix);
    matrix_destroy(&matrix2);
    matrix_destroy(&matrix3);
    return 0;
}
