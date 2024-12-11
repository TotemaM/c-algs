////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/*
 * Dynamic queue structure.
 *
 * data           : Pointer to the data array.
 * element_size   : Size in bytes of stored elements.
 * size           : Number of elements in the queue.
 * capacity       : Number of elements that the queue can store.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 * 
 * !!! Do not forget to use queue_free(...) after use, to avoid memory leaks.
 */
typedef struct Queue {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
} Queue ;

/*
 * Dynamic queue constructor
 *
 * q            : Pointer to a uninitialized Queue structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of elements the queue can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int queue(Queue* q, size_t element_size, unsigned int capacity);

/*
 * Add an element to a queue.
 *
 * q            : Pointer to a queue.
 * element      : Element to add to the queue.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int enqueue(Queue* q, const void* element);

/*
 * Remove an element from a queue.
 *
 * q            : Pointer to queue.
 * element      : Buffer to store the removed element.
 * 
 * Returns 1 if nothing to dequeu, 0 otherwise.
 */
short unsigned int dequeue(Queue* q, void* element);

/*
 * Free the memory allocated for the data stored in a queue.
 *
 * q            : Pointer to a queue
 * 
 * void
 */
void queue_free(Queue* q);

/*
 * Queue getter for the size attribute
 *
 * q            : The queue to get the size from.
 * size         : Buffer that will contain the size of the queue.
 * 
 * Returns the queue size.
 */
unsigned int queue_size(Queue* q);

/*
 * Queue getter for the size attribute
 *
 * q            : The queue to get the size from.
 * size         : Buffer that will contain the size of the queue.
 * 
 * Returns the queue capacity.
 */
unsigned int queue_capacity(Queue* q);

/*
 * Queue method printing the values of his attributes.
 *
 * q            : Pointer to a queue
 * 
 * Returns void
 */
void queue_state(Queue* q);

#endif // QUEUE_H