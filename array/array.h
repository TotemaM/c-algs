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
 * initialized    : Boolean to check if the array was initialized.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 */
typedef struct Array {
    void* data;
    size_t element_size;
    unsigned int size;
    unsigned int capacity;
    short unsigned int initialized;
} Array ;

// Array error codes
typedef enum {
    NO_ERR,     // Equals to "return 0".
    NO_INIT,    // The array is not initialized.
    IS_INIT,    // The array was already initialized.
    EMPTY,      // The array is empty.
    OOR,        // Out of range.
    SYS_ERR     // System error, see errno for potential info.
} ArrayError ;

/*
 * Dynamic array constructor
 *
 * a            : Pointer to a uninitialized Array structure.
 * element_size : Ammount of bytes needed to store one element.
 * capacity     : Number of elements the array can store at initialization.
 * Altought the data has a dynamically growing system.
 * 
 * Returns an ArrayError
 */
ArrayError array(Array* a, size_t element_size, unsigned int capacity);

/*
 * Add and element to an array.
 *
 * a            : Pointer to an array.
 * element      : Pointer to the element to add to the array.
 * 
 * Return an ArrayError
 */
ArrayError array_add(Array* a, const void* element);

/*
 * Get the value contained at given index.
 *
 * a            : Pointer to an array.
 * index        : Index of the element to get.
 * element      : Buffer to store the element.
 * 
 * Return an ArrayError
 */
ArrayError array_get(Array* a, const unsigned int* index, void* element);

/*
 * Remove an element at given index from an array.
 *
 * a            : Pointer to an array.
 * index        : Index of the element to remove.
 * 
 * Return an ArrayError
 */
ArrayError array_remove(Array* a, const unsigned int* index);

/*
 * Free the dynamic memory allocated for the data stored in an array.
 *
 * a            : Pointer to an array.
 * 
 * Return an ArrayError
 */
ArrayError array_free(Array* a);

/*
 * Get the size of an array.
 *
 * a            : Pointer to an array.
 * size         : Buffer to store the size.
 * 
 * Return an ArrayError
 */
ArrayError array_getSize(Array* a, unsigned int* size);

#endif // ARRAY_H