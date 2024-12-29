////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef STR_H
#define STR_H

/*
 * Structure of a const string of character
 *
 * data     : Pointer to the araray of characters.
 * length   : Length of the string.
 * capacity : Number of characters allocated.
 * 
 * It is absolutely not recommended to access these attributes directly,
 * use the functions provided instead.
 * 
 * !!! Do not forget to use str_free(...) after use, to avoid memory leaks.
 */
typedef struct Str {
    char* data;
    unsigned int length;
} Str ;

/*
 * Const string constructor
 *
 * s            : Pointer to a unitialized String structure.
 * arr          : Pointer to a null terminated char array.
 * 
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int str(Str* s, const char arr[]);

/*
 * Checks if the content of two strings are equal.
 *
 * s            : Pointer to a String structure.
 * t            : Pointer to a String structure.
 * 
 * Returns 1 if equal, 0 otherwise.
 */
short unsigned int str_cmp(const Str* s, const Str* t);

/*
 * Checks if the content of two null terminated char arrays are equal.
 *
 * a            : Pointer to a null terminated char array.
 * b            : Pointer to a null terminated char array.
 * 
 * Returns 1 if equal, 0 otherwise.
 */
short unsigned int char_cmp(const char a[], const char b[]);

/*
 * Checks if a string is equal to the content of a char array.
 *
 * s            : Pointer to a String structure.
 * arr          : Pointer to a null terminated char array.
 * 
 * Returns 1 if equal, 0 otherwise.
 */
short unsigned int str_cmp_char(const Str* s, const char arr[]);

/*
 * Checks if the first string contains the content of the second string.
 *
 * s            : Pointer to a String structure.
 * t            : Pointer to a String structure.
 *
 * Returns the index where subsequence is starting in first string. If not contained -1.
 */
short int str_cntn(const Str* s, const Str* t);

/*
 * Checks if a string contains the content of a char array.
 *
 * s            : Pointer to a String structure.
 * arr          : Pointer to a null terminated char array.
 *
 * Returns the index where subsequence is starting in first string. If not contained -1.
 */
short int str_cntn_char(const Str* s, const char arr[]);

// TODO short unsigned int char_cntn(const char a[], const char b[]);

/*
 * Concatenating the content of the second string to the first string.
 *
 * s            : Pointer to a String structure.
 * t            : Pointer to a String structure.
 *
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int str_cnct(Str* s, Str* t);

/*
 * Concatenating the content of a char array to a string
 *
 * s            : Pointer to a String structure.
 * arr          : Pointer to a null terminated char array.
 *
 * Returns 1 on system memory error, 0 otherwise.
 */
short unsigned int str_cnct_char(Str* s, const char arr[]);

/*
 * Getter for the "length" attribute of a string
 *
 * s            : Pointer to a string
 * 
 * Returns the length of a string.
 */
unsigned int str_length(Str* s);

/*
 * Calculate length of a null terminated char array.
 *
 * a            : Pointer to a null terminated char array.
 * 
 * Returns the length
 */
short unsigned int char_length(const char a[]);

/*
 * Prints a string
 *
 * s            : Pointer to a string
 * 
 * Returns void
 */
void str_print(Str* s);

/*
 * Frees the memory allocated for a string.
 *
 * s            : Pointer to a string
 * 
 * Returns void
 */
void str_free(Str* s);

/*
 * Frees the memory allocated for multiple strings.
 *
 * s            : Pointer to a string
 * ...          : Other pointers to string
 * NULL         : ! Mandatory ! Last parameter has to be NULL pointer.
 * 
 * Returns void
 */
void str_frees(Str* s, ...);

#endif // STR_H