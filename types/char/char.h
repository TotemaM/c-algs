////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef CHAR_H
#define CHAR_H

/*
 * Calculate length of a null terminated char array.
 *
 * a            : Pointer to a null terminated char array.
 * 
 * Returns the length
 */
short unsigned int char_length(const char a[]);

/*
 * Checks if the content of two null terminated char arrays are equal.
 *
 * a            : Pointer to a null terminated char array.
 * b            : Pointer to a null terminated char array.
 * 
 * Returns 1 if equal, 0 otherwise.
 */
short unsigned int char_cmp(const char a[], const char b[]);

// TODO short unsigned int char_cntn(const char a[], const char b[]);

#endif // CHAR_H