#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include "./utils.h"

int _levenshtein_distance(char* string1, char* string2) {
    int len_str1 = strlen(string1);
    int len_str2 = strlen(string2);

    int **matrix = (int**) malloc(sizeof(int*)*len_str1);
    int max = max2n(len_str1, len_str2);

    for (int index = 0; index < max; index++) {
        if (index < len_str1) {
            matrix[index] = (int*)malloc(sizeof(int)*len_str2);
            matrix[index][0] = index;
        }
        if (index < len_str1) {
            matrix[0][index] = index;
        }
    }

    int cost = 0,
        deletion = 0,
        insertion = 0,
        substitution = 0;

    for (int index_str1 = 1; index_str1 < len_str1; index_str1++) {
        for (int index_str2 = 1; index_str2 < len_str2; index_str2++) {
            if (string1[index_str1] == string2[index_str2]) {
                cost = 0;
            } else {
                cost = 1;
            }

            deletion = matrix[index_str1 - 1][index_str2] + 1;
            insertion = matrix[index_str1][index_str2 - 1] + 1;
            substitution = matrix[index_str1 - 1][index_str2 - 1] + cost;

            matrix[index_str1][index_str2] = min3n(
                    matrix[index_str1 - 1][index_str2] + 1,
                    matrix[index_str1][index_str2 - 1] + 1,
                    matrix[index_str1 - 1][index_str2 - 1] + cost
                    );
        }
    }
    int result = matrix[len_str1 - 1][len_str2 - 1];

    for (int index = 0; index < len_str1; index++)
        free(matrix[index]);
    free(matrix);

    return result;
}

float _simular_percentage(int distance, int len_str1, int len_str2) {
    return (len_str1 + len_str2 - distance + 0.0) / (len_str1 + len_str2 + 0.0);
}


int _checker(char c) {
    return (c != REMOVE_TAB && c!= REMOVE_NEWLINE && c!= REMOVE_SPACE);
}

float _search_include(char *target, char *content) {
    content = _remove_useless(content, _checker);
    target = _remove_useless(target, _checker);

    int len_target = strlen(target);
    int len_content = strlen(content);
    if (len_target > len_content) {
        char* tmp = target;
        target = content;
        content = tmp;
    }

    char* substring = _substr(content, 0, len_target);
    int result = _levenshtein_distance(target, substring);
    free(substring);
    int index = len_target;
    int tmp = 0;

    while (1) {
        index += len_target;
        if (!(index < len_content)) {
            break;
        }
        substring = _substr(content, index - len_target, index);
        if (tmp = _levenshtein_distance(target, substring) < result) {
            result = tmp;
        }
        free(substring);

    }

    free(content);
    free(target);
    return _simular_percentage(result, len_target, len_content);
}

#endif /*LEVENSHTEIN_H*/
