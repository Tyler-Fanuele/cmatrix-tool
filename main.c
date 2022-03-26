#include <stdio.h>
#include <stdlib.h>
#include "int_vect.h"
#include "matrix.h"

int main(int argc, char** argv) {
    //int arr[6] = {1, 2, 3, 4};
    //int arr2[6] = {7, 8, 9, 10};

    unsigned rows1, cols1, rows2, cols2;

    int op;

    if (argc < 6) {
        printf("Not enough arguments passed into main!\n");
        exit(1);
    }

    rows1 = (unsigned) atoi(argv[1]);
    cols1 = (unsigned) atoi(argv[2]);
    rows2 = (unsigned) atoi(argv[3]);
    cols2 = (unsigned) atoi(argv[4]);
    op = argv[5][0];

    MATRIX (*matrix_function)(MATRIX, MATRIX);  
    printf("got here %d %d\n", op,'*');
    switch(op) {
        case '+':
            //printf("got to +\n");
            matrix_function = &matrix_init_add;
            printf("addition\n");
            break;
        case '-':
            matrix_function = &matrix_init_subtract;
            printf("subtraction\n");
            break;
        case 'L': // * did not work for some reason
            matrix_function = &matrix_init_multply;
            printf("multplication\n");
            break;
        case 's':
            matrix_function = &matrix_init_scalar;
            printf("scalar multplication\n");
            break;
        default:
            printf("Operation not known!\n");
            exit(1);
            break;
    }  

    INT_VECT first = int_vect_init(rows1 * cols1);
    INT_VECT second = int_vect_init(rows2 * cols2);
    printf("\n");
     int temp;
    for (int i = 0; i < rows1; i++) {
        printf("input row %d of matrix 1, with %d numbers: ", i, cols1);
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &temp);
            int_vect_push(first, temp);
        }
    }

    for (int i = 0; i < rows2; i++) {
        printf("input row %d of matrix 2, with %d numbers: ", i, cols2);
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &temp);
            int_vect_push(second, temp);
        }
    }



    MATRIX matrix = matrix_init_vect(first, rows1, cols2);
    MATRIX matrix2 = matrix_init_vect(second, rows2, cols2);
    MATRIX matrix3 = matrix_math(matrix_function, matrix, matrix2);
    matrix_print(matrix);
    matrix_print(matrix2);
    for (int i = 0; i < (rows1 + 3) * 2; i++) {
        printf("-");
    }
    printf("\n");
    matrix_print(matrix3);

    matrix_destroy(&matrix);
    matrix_destroy(&matrix2);
    matrix_destroy(&matrix3);
    int_vect_destroy(&first);
    int_vect_destroy(&second);
    return 0;
}
