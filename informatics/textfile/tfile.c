////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "tfile.h"

#include <unistd.h>
#include <stdlib.h>


short unsigned int tfile(TFile* f, char path[]) {
    f->ptr = fopen(path, "r");
    if (f->ptr == NULL) { return 1; }
    f->path = path;
    fseek(f->ptr, 0, SEEK_END);
    f->size = ftell(f->ptr);
    f->content = (char*)malloc(f->size + 1);
    fseek(f->ptr, 0, SEEK_SET);
    fread(f->content, f->size, 1, f->ptr);
    f->content[f->size] = '\0';
    return 0;
}

void tfile_print(TFile* f) {
    printf("%s\n", f->content);
}

void tfile_free(TFile* f) {
    fclose(f->ptr);
    free(f->content);
}