#ifndef matrix_h
#define matrix_h

#include "int_vect.h"

typedef void* MATRIX;

MATRIX matrix_init_default();  // default constructor

MATRIX matrix_init(unsigned rows, unsigned cols);  // value constructor

MATRIX matrix_init_vect(INT_VECT vect, unsigned rows,
                        unsigned cols);  // vector constructor

MATRIX matrix_init_arr(int* arr, unsigned rows,
                       unsigned cols);  // array constructor

int matrix_at(MATRIX matrix, unsigned row,
              unsigned col);  // returns the value at the row and col specified

int matrix_capacity(MATRIX matrix);  // returns rows * cols

int matrix_rows(MATRIX matrix);  // returns rows

int matrix_cols(MATRIX matrix);  // returns cols

void matrix_destroy(MATRIX* pMatrix);  // destructor

void matrix_print(MATRIX matrix);  // prints the matrix in format

void matrix_print_debug(
    MATRIX matrix);  // prints the matrix with the cords in format

// matrix math section

MATRIX matrix_math(MATRIX (*function)(MATRIX, MATRIX), MATRIX right,
                   MATRIX left);  // allows the user to use one function with
                                  // all matrix_init_math functions

MATRIX matrix_init_add(
    MATRIX right, MATRIX left);  // returns the matrix after the + operation

MATRIX matrix_init_subtract(
    MATRIX right, MATRIX left);  // rerturns the matrix after the - operation

MATRIX matrix_init_multply(
    MATRIX right, MATRIX left);  // returns the matrix after the * operation

MATRIX matrix_init_scalar(
    MATRIX right,
    MATRIX left);  // returns the matrix after the scalar * operation

#endif
