#include <stdio.h>
#include <stdlib.h>
#include "int_vect.h"
#include "matrix.h"

int main(int argc, char** argv) {
    //INT_VECT vect = int_vect_init(2);
    INT_VECT vect = int_vect_init_arr((int []){1, 2, 3}, 3);
    
    //int_vect_push(vect, 1);
    //int_vect_push(vect, 2);

    MATRIX matrix = matrix_init_vect(vect, 1, 3);

    int_vect_destroy(&vect);
    matrix_destroy(&matrix);
    return 0;
}
