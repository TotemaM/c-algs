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
 * initialized    : Boolean to check if the queue was initialized.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 */
typedef struct Queue {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
    short unsigned int initialized;
} Queue ;

// Queue error codes
typedef enum {
    NO_ERR,
    NO_INIT,    // The queue is not initialized.
    IS_INIT,    // The queue was already initialized.
    EMPTY,      // The queue is empty.
    SYS_ERR     // System error, see errno for potential info.
} QueueError ;

/*
 * Dynamic queue constructor
 *
 * q            : Pointer to a uninitialized Queue structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of values the queue can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns a QueueError
 */
QueueError queue(Queue* q, size_t element_size, unsigned int capacity);

/*
 * Add an element to a queue.
 *
 * q            : Pointer to a queue.
 * element      : Element to add to the queue.
 * 
 * Returns a QueueError
 */
QueueError enqueue(Queue* q, const void* element);

/*
 * Remove an element from a queue.
 *
 * q            : Pointer to queue.
 * element      : Buffer to store the removed element.
 * 
 * Returns a QueueError
 */
QueueError dequeue(Queue* q, void* element);

/*
 * Free the memory allocated for a queue.
 *
 * q            : The queue to free.
 * 
 * Returns a QueueError
 */
QueueError queue_free(Queue* q);

/*
 * Queue getter for the size attribute
 *
 * q            : The queue to get the size from.
 * buffer       : Buffer that will contain the size of the queue.
 * 
 * Returns a QueueError
 */
QueueError queue_getSize(Queue* q, unsigned int* size);

#endif // QUEUE_H