#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(getVectorValue(&v, 0) == 10);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(getVectorValue(&v, 2) == 3);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*atVector(&v, 0) == 1);
    assert(*atVector(&v, 1) == 2);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*atVector(&v, 2) == 3);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*back(&v) == 3);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(*front(&v) == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }

    return 0;
}

