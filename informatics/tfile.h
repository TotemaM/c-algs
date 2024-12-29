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
#include <unistd.h>
#include <stdlib.h>

typedef struct TFile {
    char* path;
    FILE* ptr;
    unsigned int length;
    unsigned int lines;
} TFile ;

/* Text File constructor */
short unsigned int tfile(TFile* f, char path[]) {
    if (access(path, F_OK) != 0) { return 1; }
    f->path = path;
    f->length = 0;
    f->lines = 0;
    f->ptr = fopen(path, "r");
    if (f->ptr == NULL) { return 1; }
    for (char c; (c = fgetc(f->ptr)) != EOF; f->length++) {
        if (c == '\n') { f->lines++; }
    }
    fclose(f->ptr);
    return 0;
}

/* Getter for "lines" attribute. */
unsigned int tfile_lines(const TFile* f) { return f->lines; }

/* Getter for "length" attribute. */
unsigned int tfile_length(const TFile* f) { return f->length; }

/* Get the content of the file inside a char array */
short unsigned int tfile_get(TFile* f, char content[]) {
    f->ptr = fopen(f->path, "r");
    if (f->ptr == NULL) { return 1; }
    fgets(content, f->length, f->ptr);
    fclose(f->ptr);
    return 0;
}

/* Print the content of a file in the terminal */
short unsigned int tfile_print(TFile* f) {
    f->ptr = fopen(f->path, "r");
    if (f->ptr == NULL) { return 1; }
    char c;
    while ((c = fgetc(f->ptr)) != EOF) {
        printf("%c", c);
    }
    fclose(f->ptr);
    printf("\n");
    return 0;
}

/* Overwrite the content of the file. */
short unsigned int tfile_overwrite(TFile* f, const char content[]) {
    f->ptr = fopen(f->path, "w");
    if (f->ptr == NULL) { return 1; }
    fprintf(f->ptr, "%s", content);
    fclose(f->ptr);
    return 0;
}

/* Writing content at the end of the file. */
short unsigned int tfile_add(TFile* f, const char content[]) {
    f->ptr = fopen(f->path, "a");
    if (f->ptr == NULL) { return 1; }
    unsigned int i = 0;
    for (; content[i] != '\0'; i++) {
        if (content[i] == '\n') { f->lines++; }
    }
    f->length += i;
    fprintf(f->ptr, "%s", content);
    fclose(f->ptr);
    return 0;
}

/* Writing a new line with content at the end of the file. */
short unsigned int tfile_append(TFile* f, const char content[]) {
    f->ptr = fopen(f->path, "a");
    if (f->ptr == NULL) { return 1; }
    fprintf(f->ptr, "\n");
    f->lines++;
    f->length++;
    fclose(f->ptr);
    if (tfile_add(f, content) == 1) { return 1; }
    return 0;
}

#endif // TFILE_H