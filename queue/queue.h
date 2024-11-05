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
#include <stdbool.h>

typedef struct Queue Queue;

/*
 * Dynamic queue constructor :
 * @param element_size Ammount of bytes needed to store one element
 * @param capacity Number of elements that you entend to store in the queue.
 * Although the queue has a dynamic growing system.
 * @return A pointer to the dynamically allocated queue.
 */
Queue* queue(size_t element_size, int capacity);

/*
 * Add an element to a queue.
 * @param q The queue to add the element to.
 * @param element The element to add to the queue.
 * @return void
 */
void  enqueue(Queue* q, void* element);

/*
 * Remove an element from a queue.
 * @param q The queue to remove the element from.
 * @param element Buffer to store the removed element.
 * @return true if the element was removed, false if the queue is empty.
 */
bool dequeue(Queue* q, void* element);

/*
 * Free the memory allocated for a queue.
 * @param q The queue to free. 
 */
void queue_free(Queue* q);

/*
 * Queue getter for the size attribute
 * @param q The queue to get the size from.
 * @return The ammount of elements in the queue.
 */
int queue_getSize(Queue* q);

#endif // QUEUE_H