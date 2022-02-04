#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
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

bool isEmptyV(vectorVoid *v) {
    return !v->size;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination , source , v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v))
        reserveV(v, v->capacity ? v->capacity * 2 : 1);
    setVectorValueV(v, v->size, source);
    v->size++;
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "empty vector");
        exit(1);
    }
    v->size--;
}