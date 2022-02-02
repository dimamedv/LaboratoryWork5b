#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v;
    v = createVector(0);
    reserve(&v, 5);
    deleteVector(&v);

    return 0;
}

