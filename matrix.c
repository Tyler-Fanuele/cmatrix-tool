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

int matrix_at(MATRIX matrix, unsigned row, unsigned col) {
    Matrix* pMatrix = (Matrix*)matrix;
    if (row > pMatrix->r && col > pMatrix->c) {
        return int_vect_at(pMatrix->matrix, row * col + col);
    }
    return -20000;
}

void matrix_destroy(MATRIX* pMatrix) {
    Matrix* phMatrix = (Matrix*)*pMatrix;
    int_vect_destroy(&phMatrix->matrix);
    free(phMatrix);
    *pMatrix = NULL;
}