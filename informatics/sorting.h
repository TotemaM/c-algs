////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include <stdio.h>

// Generates an array with random unsigned int 0 represents
void generate(unsigned int* buffer, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        buffer[i] = rand() % size;
    }
}

// Applies a selection sort to a given array of given size.
void selection_sort(unsigned int* arr, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        unsigned int min = i;
        for (unsigned int j = i+1; size-j < size; j++) {
            if (arr[j] < arr[min]) { min = j; }
        }
        unsigned int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

#endif // SORTING_H