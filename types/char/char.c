////////////////////////////////////
// This file is under MIT License //
// https://mit-license.org/       //
//                                //
// Copyright (c) 2024 Totema      //
// https://github.com/TotemaM     //
////////////////////////////////////

short unsigned int char_length(const char arr[]) {
    unsigned int i = 0;
    while (arr[i] != '\0') { i++; }
    return i;
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

// short unsigned int char_cntn(const char a[], const char b[]) {}