#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.size = 0;
    v.capacity = n;
    v.data = malloc(n);
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    if (newCapacity == 0) {
        v->size = 0;
        v->data = NULL;
        return;
    }
    v->data = realloc(v->data, newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}





