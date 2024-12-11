////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "stack.h"

#include <string.h>
#include <stdio.h>


short unsigned int stack(Stack* s, size_t element_size, unsigned int capacity) {
    s->data = malloc(element_size * capacity);
    if (s->data == NULL) { return 1; }
    s->element_size = element_size;
    s->size = 0;
    s->capacity = capacity;
    return 0;
}

short unsigned int stack_push(Stack* s, const void* element) {
    if (s->size >= s->capacity) {
        unsigned int temp_capacity = s->capacity * 2;
        s->data = realloc(s->data, s->element_size * temp_capacity);
        if (s->data == NULL) { return 1; }
        s->capacity = temp_capacity;
    }
    memcpy(s->data + s->size * s->element_size, element, s->element_size);
    s->size++;
    return 0;
}

short unsigned int stack_pop(Stack* s, void* element) {
    if (s->size == 0) { return 1; }
    s->size--;
    memcpy(element, s->data + (s->size * s->element_size), s->element_size);
    return 0;
}

void stack_free(Stack* s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

unsigned int stack_size(const Stack* s) { return s->size; }

unsigned int stack_capacity(const Stack* s) { return s->capacity; }

void stack_state(Stack* s) {
    printf("Stack at %p\n", s);
    printf("Element size    : %lu bytes\n", s->element_size);
    printf("Used capacity   : %u\n", s->size);
    printf("Max capacity    : %u\n", s->capacity);
}