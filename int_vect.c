#include "int_vect.h"

struct int_vect {
    int* data;
    int size;
    int capacity;
};

typedef struct int_vect Int_vect;

INT_VECT int_vect_init_default() {
    Int_vect* pVect = (Int_vect*)malloc(sizeof(Int_vect));
    if (pVect != NULL) {
        pVect->size = 0;
        pVect->capacity = 10;
        pVect->data = (int*)malloc(sizeof(int) * pVect->capacity);
        if (pVect->data == NULL) {
            free(pVect);
            return NULL;
        }
    }
    return pVect;
}

INT_VECT int_vect_init(int capacity) {
    Int_vect* pVect = (Int_vect*)malloc(sizeof(Int_vect));
    if (pVect != NULL) {
        pVect->size = 0;
        pVect->capacity = capacity;
        pVect->data = (int*)malloc(sizeof(int) * pVect->capacity);
        if (pVect->data == NULL) {
            free(pVect);
            return NULL;
        }
    }
    return pVect;
}

INT_VECT int_vect_init_arr(int* arr, int capacity) {
    Int_vect* pVect = (Int_vect*)malloc(sizeof(Int_vect));
    if (pVect != NULL) {
        pVect->data = (int*)malloc(sizeof(int) * capacity);
        pVect->size = 0;
        pVect->capacity = capacity;
        if (pVect->data == NULL) {
            printf("Vector: error array init\n");
            exit(1);
        }
        for (int i = 0; i < pVect->capacity; i++) {
            pVect->data[i] = arr[i];
            pVect->size++;
        }
    }
    return pVect;
}

INT_VECT int_vect_init_copy(INT_VECT data) {
    Int_vect* pVect = (Int_vect*)malloc(sizeof(Int_vect));
    Int_vect* pData = (Int_vect*)data;

    if (pVect != NULL) {
        pVect->size = int_vect_size(data);
        pVect->capacity = int_vect_capacity(pData);
        pVect->data = (int*)malloc(sizeof(int) * pVect->capacity);
        if (pData->data == NULL) {
            free(pVect);
            exit(1);
        }
    }
    for (int i = 0; i < pVect->size; i++) {
        //int_vect_push(pVect, pData->data[i]);
        pVect->data[i] = pData->data[i];
        //printf(";%d;", pVect->data[i]);
    }
    return pVect;
}

void int_vect_push(INT_VECT vect, int value) {
    Int_vect* pVect = (Int_vect*)vect;
    if (pVect->size >= pVect->capacity) {
        int* temp = (int*)malloc(sizeof(int) * pVect->capacity + 10);
        if (temp == NULL)
        {
            exit(1);
        }
        for (int i = 0; i < pVect->capacity; i++) {
            temp[i] = pVect->data[i];
        }
        pVect->capacity = pVect->capacity + 10;
        free(pVect->data);
        pVect->data = temp;
    }
    
    pVect->data[pVect->size] = value;
    pVect->size++;
}

int int_vect_pop(INT_VECT vect) {
    Int_vect* pVect = (Int_vect*)vect;
    int temp = pVect->data[pVect->size];
    pVect->size--;
    return temp;
}

int int_vect_size(INT_VECT vect) {
    return (((Int_vect*)vect)->size);
}

int int_vect_capacity(INT_VECT vect) {
    return (((Int_vect*)vect)->capacity);
}

int int_vect_at(INT_VECT vect, int index) {
    Int_vect* pVect = (Int_vect*)vect;
    /*
    if (index >= 0 && index <= pVect->size) {
        return pVect->data[index];
    }
    return -200000;
    */
   //printf(" (%d | %d) \n", index, pVect->data[index]);
   return pVect->data[index];
}

void int_vect_destroy(INT_VECT* pVect) {
    Int_vect* phVect = (Int_vect*)*pVect;
    free(phVect->data);
    free(phVect);
    *pVect = NULL;
}
