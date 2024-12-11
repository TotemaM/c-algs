////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

/*
 * Dynamic Array structure.
 *
 * data           : Pointer to the data array.
 * element_size   : Size in bytes of stored elements.
 * size           : Number of elements in the array.
 * capacity       : Number of elements that the array can store.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 * 
 * !!! Do not forget to use array_free(...) after use, to avoid memory leaks.
 */
typedef struct Array {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
} Array ;

/*
 * Dynamic array constructor
 *
 * a            : Pointer to a uninitialized Array structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of elements the array can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int array(Array* a, size_t element_size, unsigned int capacity);

/*
 * Add an element at the end of the array.
 *
 * a            : Pointer to an array.
 * element      : Pointer to the element to add to the array.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int array_add(Array* a, const void* element);

/*
 * Set a value at given index.
 *
 * a            : Pointer to an array.
 * index        : Index of the element to set.
 * element      : Pointer to the element to set to the array.
 * 
 * Returns 1 if index is out of range, 0 otherwise.
 */
short unsigned int array_set(Array* a, const unsigned int index, const void* element);

/*
 * Get the value contained at given index.
 *
 * a            : Pointer to an array.
 * index        : Index of the element to get.
 * element      : Buffer to store the element.
 * 
 * Returns 1 if index is out of range, 0 otherwise.
 */
short unsigned int array_get(Array* a, const unsigned int index, void* element);

/*
 * Free the dynamic memory allocated for the data stored in an array.
 *
 * a            : Pointer to an array.
 * 
 * Return void
 */
void array_free(Array* a);

/*
 * Get the size of an array.
 *
 * a            : Pointer to an array.
 * 
 * Return void
 */
unsigned int array_size(Array* a);

/*
 * Get the capacity of an array.
 *
 * a            : Pointer to an array.
 * 
 * Return void
 */
unsigned int array_capacity(Array* a);

/*
 * Array method printing the values of his attributes.
 *
 * a            : Pointer to an array.
 * 
 * Return void
 */
void array_state(Array* a);

#endif // ARRAY_H