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

// Generates an array with random unsigned int 0 represents
void generate(unsigned int* buffer, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        buffer[i] = rand() % size;
    }
}

#endif // RNG_H