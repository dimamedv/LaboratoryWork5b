#include <stdlib.h>
#include <stdio.h>
#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.baseTypeSize = baseTypeSize;
    v.size = 0;
    v.capacity = n;
    v.data = malloc(v.capacity * v.baseTypeSize);
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->capacity = newCapacity;
    if (newCapacity == 0) {
        v->size = 0;
        v->data = NULL;
        return;
    }
    v->data = realloc(v->data, v->capacity * v->baseTypeSize);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}