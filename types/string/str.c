#include "str.h"

#include <stdlib.h>
#include <stdio.h>

short unsigned int str(Str* s, const char arr[]) {
    for (s->length = 0; arr[s->length] != '\0'; s->length++ );
    s->data = malloc((sizeof(char) * s->length)+1);
    if (s->data == NULL) { return 1; }
    for (unsigned int i = 0; i < s->length; i++) {
        s->data[i] = arr[i];
    }
    s->data[s->length++] = '\0';
    return 0;
}

short unsigned int str_cmp(const Str* s, const Str* t) {
    if (s->length != t->length) { return 0; }
    for (unsigned int i = 0; i < s->length; i++) {
        if (s->data[i] != t->data[i]) { return 0; }
    }
    return 1;
}

short unsigned int str_cmp_char(const Str* s, const char arr[]) {
    for (unsigned int i = 0; arr[i] != '\0'; i++) {
        if (i >= s->length) { return 0; }
        if (s->data[i] != arr[i]) { return 0; }
    }
    return 1;
}

//short unsigned int str_cntn(const Str* s, const Str* t) {}

//short unsigned int str_cntn_char(const Str* s, const char arr[]) {}

//void str_cnc(Str* s, Str* t) {}

//void str_cnc_char(Str* s, const char* arr) {}

unsigned int str_length(Str* s) { return s->length; }

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