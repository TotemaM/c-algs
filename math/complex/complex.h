////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef COMPLEX_H
#define COMPLEX_H

/*
 * Structure of a mathematical complex number.
 * 
 * re       : Real part
 * im       : Imaginary part
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 * 
 * There's no constructor provided. Initialize like this : 
 * Complex z = {a, b}, which represents z = a+bi
 */
typedef struct Complex {
    int re;
    int im;
} Complex ;

/* z += z2 */
void complex_add(Complex* z, const Complex* z2);

/* z -= z2 */
void complex_sub(Complex* z, const Complex* z2);

/* z *= z2 */
void complex_mul(Complex* z, const Complex* z2);

/* Conjugates z */
void complex_conj(Complex* z);

/* Returns |z| */
float complex_abs(const Complex* z);

/* z = z ** p */
void complex_pow(Complex* z, const unsigned int p);

/* Getter for the "real" part. */
int complex_re(const Complex* z);

/* Getter for the imaginary part. */
int complex_im(const Complex* z);

/* Printing a complex number. */
int complex_print(const Complex* z);

#endif // COMPLEX_H