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
#include <stdbool.h>

/*
 * Dynamic stack structure.
 *
 * data           : Pointer to the data array.
 * element_size   : Size in bytes of stored elements.
 * size           : Number of elements in the stack.
 * capacity       : Number of elements that the stack can store.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 * 
 * !!! Do not forget to use stack_free(...) after use, to avoid memory leaks.
 */
typedef struct Stack {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
} Stack ;

/*
 * Dyanmic stack constructor
 *
 * s            : Pointer to a unitialized Stack structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of elements the stack can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int stack(Stack* s, size_t element_size, unsigned int capacity);

/*
 * Add an element to a stack.
 *
 * s            : Pointer to a stack.
 * element      : Element to add to the stack.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int stack_push(Stack* s, const void* element);

/*
 * Remove an element from a stack.
 *
 * s            : Pointer to a stack.
 * element      : Buffer to store the removed value.
 * 
 * Returns 1 if nothing to pop, 0 otherwise.
 */
short unsigned int stack_pop(Stack* s, void* element);

/*
 * Free the memory allocated for the data stored in a stack.
 *
 * s            : Pointer to a stack
 * 
 * Returns void
 */
void stack_free(Stack* s);

/*
 * Stack getter for the "size" attribute.
 *
 * s            : Pointer to a stack
 * 
 * Returns stack used size.
 */
unsigned int stack_size(const Stack* s);

/*
 * Stack getter for the "capacity" attribute.
 *
 * s            : Pointer to a stack
 * 
 * Returns stack capacity.
 */
unsigned int stack_capacity(const Stack* s);

/*
 * Stack method printing the values of his attributes.
 *
 * s            : Pointer to a stack
 * 
 * Returns void
 */
void stack_state(Stack* s);

#endif // STACK_H