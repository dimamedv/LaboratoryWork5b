#ifndef LABORATORY_WORK_5B_VECTORVOID_H
#define LABORATORY_WORK_5B_VECTORVOID_H

#include <opencl-c-base.h>
#include "limits.h"

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;



#endif //LABORATORY_WORK_5B_VECTORVOID_H
