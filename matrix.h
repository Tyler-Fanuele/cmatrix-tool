#ifndef matrix_h
#define matrix_h

#include "int_vect.h"

typedef void* MATRIX;

MATRIX matrix_init_default();

MATRIX matrix_init(unsigned rows, unsigned cols);

MATRIX matrix_init_vect(INT_VECT vect, unsigned rows, unsigned cols);

int matrix_at(MATRIX matrix, unsigned row, unsigned col);

void matrix_destroy(MATRIX* pMatrix);


#endif
