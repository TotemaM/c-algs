////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "queue.h"

#include <string.h>
#include <stdio.h>

short unsigned int queue(Queue* q, size_t element_size, unsigned int capacity) {
    q->element_size = element_size;
    q->size = 0;
    q->data = malloc(element_size * capacity);
    if (q->data == NULL) { return 1; }
    q->capacity = capacity;
    return 0;
}

short unsigned int enqueue(Queue* q, const void* element) {
    if (q->size >= q->capacity) {
        unsigned int temp_capacity = q->capacity * 2;
        void* temp = realloc(q->data, q->element_size * temp_capacity);
        if (temp == NULL) { return 1; }
        q->data = temp;
        q->capacity = temp_capacity;
    }
    memcpy((char*)q->data + q->size * q->element_size, element, q->element_size);
    q->size++;
    return 0;
}

short unsigned int dequeue(Queue* q, void* element) {
    if (q->size == 0) { return 1; }
    memcpy(element, q->data, q->element_size);
    q->size--;
    memmove(q->data, (char*)q->data + q->element_size, q->size * q->element_size);
    return 0;
}

void queue_free(Queue* q) {
    free(q->data);
    q->data = NULL;
    q->size = 0;
    q->capacity = 0;
}

unsigned int queue_size(Queue* q) { return q->size; }

unsigned int queue_capacity(Queue* q) { return q->capacity; }

void queue_state(Queue* q) {
    printf("Queue at %p\n", q);
    printf("Element size    : %lu bytes\n", q->element_size);
    printf("Used capacity   : %u\n", q->size);
    printf("Max capacity    : %u\n", q->capacity);
}