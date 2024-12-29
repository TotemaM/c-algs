////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef RNG_H
#define RNG_H

#include <stdlib.h>

/*
 * Fills a given array of given size, with unsigned int, ranged 
 * between [0, size[.
 */
void rand_arr(unsigned int* buffer, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        buffer[i] = rand() % size;
    }
}

#endif // RNG_H