////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

/*
 * Dynamic stack structure.
 *
 * data           : Pointer to the data array.
 * element_size   : Size in bytes of stored elements.
 * size           : Number of elements in the stack.
 * capacity       : Number of elements that the stack can store.
 * initialized    : Boolean to check if the stack was initialized.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 */
typedef struct Stack {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
    short unsigned int initialized;
} Stack ;

// Stack error codes
typedef enum {
    NO_ERR,     // Equals to "return 0".
    NO_INIT,    // The queue is not initialized.
    IS_INIT,    // The queue was already initialized.
    EMPTY,      // The queue is empty.
    SYS_ERR     // System error, see errno for potential info.
} StackError ;

/*
 * Dyanmic stack constructor
 *
 * s            : Pointer to a uniitialized Stack structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of elements the stack can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns a StackError
 */
StackError stack(Stack* s, size_t element_size, unsigned int capacity);

/*
 * Add an element to a stack.
 *
 * q            : Pointer to a stack.
 * element      : Element to add to the stack.
 * 
 * Return a StackError
 */
StackError stack_push(Stack* s, const void* element);

/*
 * Remove an element from a stack.
 *
 * q            : Pointer to a stack.
 * element      : Buffer to store the removed value.
 * 
 * Returns a StackError.
 */
StackError stack_pop(Stack* s, void* element);

/*
 * Free the memory allocated for the data stored in a stack.
 *
 * q            : Pointer to a stack
 * 
 * Returns a StackError.
 */
StackError stack_free(Stack* s);

/*
 * Stack getter for the "size" attribute.
 *
 * q            : Pointer to a stack
 * size         : Buffer that will contain the size of the queue.
 * 
 * Returns a StackError.
 */
StackError stack_getSize(Stack* s, unsigned int* size);

#endif // STACK_H