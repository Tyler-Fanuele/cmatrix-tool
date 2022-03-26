#ifndef int_vect_h
#define int_vect_h
#include <stdlib.h>
#include <stdio.h>

typedef void* INT_VECT;

INT_VECT int_vect_init_default(); // default constructor

INT_VECT int_vect_init(int capacity); // capacity constructor

INT_VECT int_vect_init_copy(INT_VECT data); // copy constructor

void int_vect_push(INT_VECT vect, int value); // push, pushes a item to the back s

int int_vect_pop(INT_VECT vect); // pop, pops a item off the back

int int_vect_size(INT_VECT vect); // returns the size of the vector

int int_vect_capacity(INT_VECT vect); // returns the capacity of the vector

int int_vect_at(INT_VECT vect, int index); // returns the int at the index if in range

void int_vect_destroy(INT_VECT* vect); // frees the vector

#endif
