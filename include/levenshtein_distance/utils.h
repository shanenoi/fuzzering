#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <string.h>

#define _min3n(a, b, c) (a+b-abs(a-b)+c*2)/4 - abs(a+b-abs(a-b)-c*2)/4
#define _max2n(a, b) (a + b + abs(a - b)) / 2

#define REMOVE_SPACE ' '
#define REMOVE_NEWLINE '\n'
#define REMOVE_TAB '\t'

char* _substr(const char *src, int start, int end) {
    int len = end - start;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(dest, (src + start), len);
    return dest;
}

char* _remove_useless(char* string, int (*checker)(char)) {
    int string_len = strlen(string);
    char *result = (char*) malloc(string_len);
    int result_index = 0;
    for (int index = 0; index < string_len; index++) {
        if (checker(string[index]))
            result[result_index++] = string[index];
    }
    return result;
}

#endif /*UTILS_H*/
