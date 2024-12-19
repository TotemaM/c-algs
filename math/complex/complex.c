////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "complex.h"

#include <stdio.h>
#include <math.h>

void complex_add(Complex* z, const Complex* z2) {
    z->re += z2->re;
    z->im += z2->im;
}

void complex_sub(Complex* z, const Complex* z2){
    z->re -= z2->re;
    z->im -= z2->im;
}

void complex_mul(Complex* z, const Complex* z2) {
    int temp = (z->re * z2->re) - (z->im * z2->im);
    z->im = (z->re * z2->im) + (z2->re * z->im);
    z->re = temp;
}

void complex_conj(Complex* z) { z->im *= -1; }

float complex_abs(const Complex* z) { return sqrt(z->re*z->re + z->im*z->im); }

void complex_pow(Complex* z, const unsigned int p) { 
    Complex temp = *z;
    for (unsigned int i = 1; i < p; i++) {
        complex_mul(z, &temp);
    }
}

int complex_re(const Complex* z) { return z->re; }

int complex_im(const Complex* z) { return z->im; }

int complex_print(const Complex* z){
    if (z->im < 0) { printf("%i%ii\n", z->re, z->im); }
    else if (z->im > 0) { printf("%i+%ii\n", z->re, z->im); }
    else { printf("%i\n", z->re); }
}