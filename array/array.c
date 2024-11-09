////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "array.h"

#include <string.h>

ArrayError array(Array* a, size_t element_size, unsigned int capacity) {
    if (a->initialized == 1) { return IS_INIT; }
    a->data = malloc(element_size * capacity);
    if (a->data == NULL) return SYS_ERR;
    a->element_size = element_size;
    a->size = 0;
    a->capacity = capacity;
    a->initialized = 1;
    return NO_ERR;
}

ArrayError array_add(Array* a, const void* element) {
    if (a->initialized == 0) { return NO_INIT; }
    if (a->size == a->capacity) {
        void* temp = realloc(a->data, a->element_size * a->capacity * 2);
        if (temp == NULL) return SYS_ERR;
        a->data = temp;
        a->capacity *= 2;
    }
    memcpy(a->data + a->element_size * a->size, element, a->element_size);
    a->size++;
    return NO_ERR;
}

ArrayError array_get(Array* a, const unsigned int* index, void* element) {
    if (a->initialized == 0) { return NO_INIT; }
    if (*index >= a->size) { return OOR; }
    memcpy(element, a->data + a->element_size * *index, a->element_size);
    return NO_ERR;
}

ArrayError array_remove(Array* a, const unsigned int* index) {
    if (a->initialized == 0) { return NO_INIT; }
    if (*index >= a->size) { return OOR; }
    memmove(a->data + a->element_size * *index, a->data + a->element_size * (*index + 1), a->element_size * (a->size - *index - 1));
    a->size--;
    return NO_ERR;
}

ArrayError array_free(Array* a) {
    if (a->initialized == 0) { return NO_INIT; }
    free(a->data);
    a->data = NULL;
    a->size = 0;
    a->capacity = 0;
    a->initialized = 0;
    return NO_ERR;
}

ArrayError array_getSize(Array* a, unsigned int* size) {
    if (a->initialized == 0) { return NO_INIT; }
    *size = a->size;
    return NO_ERR;
}