////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

#include "str.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

short unsigned int str(Str* s, const char arr[]) {
    for (s->length = 0; arr[s->length] != '\0'; s->length++ );
    s->data = malloc((sizeof(char) * s->length)+1);
    if (s->data == NULL) { return 1; }
    for (unsigned int i = 0; i < s->length; i++) {
        s->data[i] = arr[i];
    }
    s->data[s->length+1] = '\0';
    return 0;
}

short unsigned int str_cmp(const Str* s, const Str* t) {
    if (s->length != t->length) { return 0; }
    for (unsigned int i = 0; i < s->length; i++) {
        if (s->data[i] != t->data[i]) { return 0; }
    }
    return 1;
}

short unsigned int char_cmp(const char a[], const char b[]) {
    unsigned int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) { return 0; }
        i++;
    }
    if (a[i] != b[i]) { return 0; }
    return 1;
}

short unsigned int str_cmp_char(const Str* s, const char arr[]) {
    for (unsigned int i = 0; arr[i] != '\0'; i++) {
        if (i >= s->length) { return 0; }
        if (s->data[i] != arr[i]) { return 0; }
    }
    return 1;
}

short int str_cntn(const Str* s, const Str* t) {
    if (t->length > s->length) { return -1; }
    for (unsigned int i = 0; i < s->length; i++) {
        unsigned int j = 0;
        while (j < t->length-1 && s->data[i+j] == t->data[j]) { j++; }
        if (j == t->length-1 && s->data[i+j] == t->data[j]) { return i; }
    }
    return -1;
}

short int str_cntn_char(const Str* s, const char arr[]) {
    unsigned int a_len = 0;
    for (;arr[a_len] != '\0'; a_len++);
    if (a_len > s->length) { return -1; }
    for (unsigned int i = 0; i < s->length; i++) {
        unsigned int j = 0;
        while (j < a_len-1 && s->data[i+j] == arr[j]) { j++; }
        if (j == a_len-1 && s->data[i+j] == arr[j]) { return i; }
    }
    return -1;
}

// short unsigned int char_cntn(const char a[], const char b[]) {}

short unsigned int str_cnct(Str* s, Str* t) {
    unsigned int temp = s->length + t->length;
    s->data = realloc(s->data, sizeof(char) * (temp) + 1);
    if (s->data == NULL) { return 1; }
    for (unsigned int i = s->length; i < temp; i++) {
        s->data[i] = t->data[i-s->length];
    }
    s->data[temp] = '\0';
    s->length = temp;
    return 0;
}

short unsigned int str_cnct_char(Str* s, const char arr[]) {
    unsigned int a_len = 0;
    for (;arr[a_len] != '\0'; a_len++);
    unsigned int temp = s->length + a_len;
    s->data = realloc(s->data, sizeof(char) * (temp) + 1);
    if (s->data == NULL) { return 1; }
    for (unsigned int i = s->length; i < temp; i++) {
        s->data[i] = arr[i-s->length];
    }
    s->data[temp] = '\0';
    s->length = temp;
    return 0;
}

unsigned int str_length(Str* s) { return s->length; }

short unsigned int char_length(const char arr[]) {
    unsigned int i = 0;
    while (arr[i] != '\0') { i++; }
    return i;
}

void str_print(Str* s) {
    for (unsigned int i = 0; i < s->length; i++) {
        printf("%c", s->data[i]);
    }
    printf("\n");
}

void str_free(Str* s) {
    free(s->data);
    s->length = 0;
}

void str_frees(Str* s, ...) {
    va_list args;
    va_start(args, s);

    Str* current = s;
    while (current != NULL) {
        free(current->data);
        current->length = 0;
        current = va_arg(args, Str *);
    }
    va_end(args);
}