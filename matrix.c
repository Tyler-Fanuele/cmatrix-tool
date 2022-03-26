#include "matrix.h"

#include <stdlib.h>

struct matrix {
    unsigned r;
    unsigned c;
    INT_VECT matrix;
};

typedef struct matrix Matrix;

MATRIX matrix_init_default() {
    Matrix* pMatrix = (Matrix*)malloc(sizeof(Matrix));
    if (pMatrix != NULL) {
        pMatrix->r = 1;
        pMatrix->c = 1;
        pMatrix->matrix = int_vect_init(pMatrix->r * pMatrix->c);
        if (pMatrix->matrix == NULL) {
            //int_vect_destroy(pMatrix->matrix);
            free(pMatrix);
            return NULL;
        }
    }
    return pMatrix;
}

MATRIX matrix_init(unsigned rows, unsigned cols) {
    Matrix* pMatrix = (Matrix*)malloc(sizeof(Matrix));
    if (pMatrix != NULL) {
        pMatrix->r = rows;
        pMatrix->c = cols;
        pMatrix->matrix = int_vect_init(pMatrix->r * pMatrix->c);
        if (pMatrix->matrix == NULL) {
            int_vect_destroy(pMatrix->matrix);
            return NULL;
        }
    }
    return pMatrix;
}

MATRIX matrix_init_vect(INT_VECT vect, unsigned rows, unsigned cols) {
    Matrix* pMatrix = (Matrix*)malloc(sizeof(Matrix));
    pMatrix->r = rows;
    pMatrix->c = cols;
    if (rows * cols != int_vect_size(vect)) {
        printf("Matrix: Out of range! %d, %d, %d, %d\n", rows, cols,
               rows * cols, int_vect_size(vect));
        exit(1);
    }
    pMatrix->matrix = int_vect_init_copy(vect);
    return pMatrix;
}

MATRIX matrix_init_arr(int* arr, unsigned rows, unsigned cols) {
    Matrix* pMatrix = (Matrix*)malloc(sizeof(Matrix));
    if (pMatrix) {
        pMatrix->r = rows;
        pMatrix->c = cols;
        pMatrix->matrix = int_vect_init_arr(arr, pMatrix->r * pMatrix->c);
    }
    return pMatrix;
}

int matrix_at(MATRIX matrix, unsigned row, unsigned col) {
    Matrix* pMatrix = (Matrix*)matrix;
    if (row <= pMatrix->r && col <= pMatrix->c) {
        
        //printf("[%d]", temp);
        return int_vect_at(pMatrix->matrix, row * pMatrix->c + col);
    }
    return -2000;
}

int matrix_capacity(MATRIX matrix) {
    return ((Matrix*) matrix)->c * ((Matrix*) matrix)->r;
}

int matrix_rows(MATRIX matrix) {
    return ((Matrix*) matrix)->r;
}

int matrix_cols(MATRIX matrix) {
    return ((Matrix*) matrix)->c;
}

void matrix_destroy(MATRIX* pMatrix) {
    Matrix* phMatrix = (Matrix*)*pMatrix;
    int_vect_destroy(&phMatrix->matrix);
    free(phMatrix);
    *pMatrix = NULL;
}

void matrix_print(MATRIX matrix) {
     Matrix* pMatrix = (Matrix*)matrix;
     for (int i = 0; i < pMatrix->r; i++) {
         for (int j = 0; j < pMatrix->c; j++) {
             printf(" %d ", matrix_at(pMatrix, i, j));
         }
         printf("\n");
     }
}

void matrix_print_debug(MATRIX matrix) {
     Matrix* pMatrix = (Matrix*)matrix;
     for (int i = 0; i < pMatrix->r; i++) {
         for (int j = 0; j < pMatrix->c; j++) {
             printf(" %d (%d, %d)", matrix_at(pMatrix, i, j), i, j);
         }
         printf("\n");
     }
}
