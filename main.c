#include <stdio.h>
#include <stdlib.h>
#include "int_vect.h"
#include "matrix.h"

int main(int argc, char** argv) {
    //INT_VECT vect = int_vect_init(2);
    int arr[3] = {1, 2, 3};
    INT_VECT vect = int_vect_init_arr(arr, 3);

    //printf("%d\n", int_vect_size(vect));
    
    //int_vect_push(vect, 1);
    //int_vect_push(vect, 2);

    MATRIX matrix = matrix_init_vect(vect, 1, 3);
    matrix_print(matrix);

    int_vect_destroy(&vect);
    matrix_destroy(&matrix);
    return 0;
}
