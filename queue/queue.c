////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "queue.h"

#include <string.h>

QueueError queue(Queue* q, size_t element_size, unsigned int capacity) {
    if (q->initialized == 1) { return IS_INIT; }
    q->element_size = element_size;
    q->size = 0;
    q->data = malloc(element_size * capacity);
    if (q->data == NULL) { return SYS_ERR; }
    q->capacity = capacity;
    q->initialized = 1;
    return 0;
}

QueueError enqueue(Queue* q, const void* element) {
    if (q->initialized == 0) { return NO_INIT; }
    if (q->size >= q->capacity) {
        q->capacity *= 2;
        void* temp = realloc(q->data, q->capacity * q->element_size);
        if (temp == NULL) { return SYS_ERR; }
        q->data = temp;
    }
    memcpy((char*)q->data + q->size * q->element_size, element, q->element_size);
    q->size++;
    return 0;
}

QueueError dequeue(Queue* q, void* element) {
    if (q->initialized == 0) { return NO_INIT; }
    if (q->size == 0) { return EMPTY; }
    memcpy(element, q->data, q->element_size);
    q->size--;
    memmove(q->data, (char*)q->data + q->element_size, q->size * q->element_size);
    return 0;
}

QueueError queue_free(Queue* q) {
    if (q->initialized == 0) { return NO_INIT; }
    free(q->data);
    q->data = NULL;
    q->size = 0;
    q->capacity = 0;
    q->initialized = 0;
    return 0;
}

QueueError queue_getSize(Queue* q, unsigned int* size) {
    if (q->initialized == 0) { return NO_INIT; }
    *size = q->size;
    return 0;
}