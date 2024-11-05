////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "queue/queue.h"

#include <stdio.h>
#include <string.h>

/*
 * Queue structure definition.
 * `data`           : Pointer to the data array.
 * `element_size`   : Size in bytes of stored elements.
 * `size`           : Number of elements in the queue.
 * `capacity`       : Number of elements that the queue can store.
 */
struct Queue {
    void* data;
    size_t element_size;
    int size;
    int capacity;
    bool initialized;
};

Queue* queue(size_t element_size, int capacity) {
    Queue* q = malloc(sizeof(Queue));
    if (q == NULL) { perror("Failed to initialize queue"); }
    q->element_size = element_size;
    q->size = 0;
    q->capacity = capacity;
    q->initialized = true;
    q->data = malloc(capacity * element_size);
    if (q->data == NULL) { perror("Failed to initialize queue"); }
    return q;
}

void enqueue(Queue* q, void* element) {
    if (!q->initialized) { perror("Queue not initialized"); }
    if (q->size >= q->capacity) {
        q->capacity *= 2;
        void* temp = realloc(q->data, q->capacity * q->element_size);
        if (temp == NULL) { perror("Failed to resize queue"); }
        q->data = temp;
    }
    memcpy((char*)q->data + q->size * q->element_size, element, q->element_size);
    q->size++;
}

bool dequeue(Queue* q, void* element) {
    if (!q->initialized) { perror("Queue not initialized or empty"); }
    if (q->size == 0) { return false; }
    memcpy(element, q->data, q->element_size);
    q->size--;
    memmove(q->data, (char*)q->data + q->element_size, q->size * q->element_size);
    return true;
}

void queue_free(Queue* q) {
    if (!q->initialized) { perror("Queue not initialized"); }
    free(q->data);  
    q->data = NULL;   
    q->size = 0;   
    q->capacity = 0;   
    q->initialized = false;
    free(q);
}

int queue_getSize(Queue* q) {
    if (!q->initialized) { perror("Queue not initialized"); }
    return q->size;
}