////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "array.h"

#include <string.h>
#include <stdio.h>

short unsigned int array(Array* a, size_t element_size, unsigned int capacity) {
    a->data = malloc(element_size * capacity);
    if (a->data == NULL) { return 1; }
    a->element_size = element_size;
    a->size = 0;
    a->capacity = capacity;
    return 0;
}

short unsigned int array_add(Array* a, const void* element) {
    if (a->size == a->capacity) {
        void* temp = realloc(a->data, a->element_size * a->capacity * 2);
        if (temp == NULL) { return 1; }
        a->data = temp;
        a->capacity *= 2;
    }
    memcpy(a->data + a->element_size * a->size, element, a->element_size);
    a->size++;
    return 0;
}

short unsigned int array_set(Array* a, const unsigned int index, const void* element) {
    if (index >= a->size) { return 1; }
    memcpy(a->data + index * a->element_size, element, a->element_size);
    return 0;
}

short unsigned int array_get(Array* a, const unsigned int index, void* element) {
    if (index >= a->size) { return 1; }
    memcpy(element, a->data + a->element_size * index, a->element_size);
    return 0;
}

void array_free(Array* a) {
    free(a->data);
    a->data = NULL;
    a->capacity = 0;
}

unsigned int array_size(Array* a) { return a->size; }

unsigned int array_capacity(Array* a) { return a->capacity; }

void array_state(Array* a) {
    printf("Array at %p\n", a);
    printf("Element size        : %lu bytes\n", a->element_size);
    printf("Size                : %u\n", a->size);
    printf("Allocated capacity  : %u\n", a->capacity);
}