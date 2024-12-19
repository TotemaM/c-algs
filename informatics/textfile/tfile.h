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
    char* content;
    unsigned int size;
    unsigned int lines;
} TFile ;

short unsigned int tfile(TFile* f, char path[]);

void tfile_free(TFile* f);

void tfile_print(TFile* f);

#endif // TFILE_H