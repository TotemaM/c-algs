////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "stack.h"

#include <string.h>

StackError stack(Stack* s, size_t element_size, unsigned int capacity) {
    if (s->initialized == 1) { return IS_INIT; }
    s->element_size = element_size;
    s->size = 0;
    s->data = malloc(element_size * capacity);
    if (s->data == NULL) { return SYS_ERR; }
    s->capacity = capacity;
    s->initialized = 1;
    return 0;
}

StackError stack_push(Stack* s, const void* element) {
    if (s->initialized == 0) { return NO_INIT; }
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * s->element_size);
        if (s->data == NULL) { return SYS_ERR; }
    }
    memcpy((char*)s->data + s->size * s->element_size, element, s->element_size);
    s->size++;
    return 0;
}

StackError stack_pop(Stack* s, void* element) {
    if (s->initialized == 0) { return NO_INIT; }
    if (s->size == 0) { return EMPTY; }
    s->size--;
    memcpy(element, (char*)s->data + s->size * s->element_size, s->element_size);
    return 0;
}

StackError stack_free(Stack* s) {
    if (s->initialized) { return NO_INIT; }
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
    s->initialized = 0;
    return 0;
}

StackError stack_getSize(Stack* s, unsigned int* size) {
    if (s->initialized == 0) { return NO_INIT; }
    *size = s->size;
    return 0;
}
