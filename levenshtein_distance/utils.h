// Copyright 2021 Shanenoi

#ifndef LEVENSHTEIN_DISTANCE_UTILS_H_
#define LEVENSHTEIN_DISTANCE_UTILS_H_

#include "stdlib.h"
#include "string.h"

#define _max2n(a, b) (a + b + abs(a - b)) / 2
#define _min2n(a, b) (a + b - abs(a - b)) / 2
int _accepted_chars(char);
char* _remove_useless(char*, int (*checker)(char));
char* _substr(const char*, int, int);

#define SPACE ' '
#define NEWLINE '\n'
#define TAB '\t'

int _accepted_chars(char c) {
    return (c != TAB && c!= NEWLINE && c!= SPACE);
}

char* _substr(const char *src, int start, int end) {
    int len = end - start;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(dest, (src + start), len);
    return dest;
}

char* _remove_useless(char *string, int (*checker)(char)) {
    int string_len = strlen(string);
    char *result = (char*) malloc(string_len);
    int result_index = 0;
    for (int index = 0; index < string_len; index++) {
        if (checker(string[index]))
            result[result_index++] = string[index];
    }
    return result;
}

#endif  // LEVENSHTEIN_DISTANCE_UTILS_H_
