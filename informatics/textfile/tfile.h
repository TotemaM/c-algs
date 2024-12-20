////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#ifndef TFILE_H
#define TFILE_H

#include <stdio.h>

typedef struct TFile {
    char* path;
    FILE* ptr;
    unsigned int length;
    unsigned int lines;
} TFile ;

/* Text File constructor */
short unsigned int tfile(TFile* f, char path[]);

/* Getter for "lines" attribute. */
unsigned int tfile_lines(const TFile* f);

/* Getter for "length" attribute. */
unsigned int tfile_length(const TFile* f);

/* Get the content of the file inside a char array */
short unsigned int tfile_get(TFile* f, char content[]);

/* Print the content of a file in the terminal */
short unsigned int tfile_print(TFile* f);

/* Overwrite the content of the file. */
short unsigned int tfile_overwrite(TFile* f, const char content[]);

/* Writing content at the end of the file. */
short unsigned int tfile_add(TFile* f, const char content[]);

/* Writing a new line with content at the end of the file. */
short unsigned int tfile_append(TFile* f, const char content[]);

#endif // TFILE_H