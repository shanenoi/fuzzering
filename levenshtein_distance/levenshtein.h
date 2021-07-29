#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

/* in some document the default cost is 2*/
#define DEFAULT_COST 1

#include "./utils.h"

int _levenshtein_distance(char*, char*);
float _simular_percentage(int, int, int);
float _search_include(char*, char *);

int _levenshtein_distance(char *string1, char *string2) {
    int len_str1 = strlen(string1) + 1;
    int len_str2 = strlen(string2) + 1;

    int **matrix = (int**) malloc(sizeof(int*)*len_str1);
    int max = _max2n(len_str1, len_str2);

    int cost,
	result,
        deletion,
        insertion,
        substitution;

    for (int index = 0; index < max; index++) {
        if (index < len_str1) {
            matrix[index] = (int*)malloc(sizeof(int)*len_str2);
            matrix[index][0] = index;
        }
        if (index < len_str2) {
            matrix[0][index] = index;
        }
    }

    for (int index_str1 = 1; index_str1 < len_str1; index_str1++) {
        for (int index_str2 = 1; index_str2 < len_str2; index_str2++) {
            if (string1[index_str1 - 1] == string2[index_str2 - 1]) {
                cost = 0;
            } else {
                cost = DEFAULT_COST;
            }

            deletion = matrix[index_str1 - 1][index_str2] + 1;
            insertion = matrix[index_str1][index_str2 - 1] + 1;
            substitution = matrix[index_str1 - 1][index_str2 - 1] + cost;

            matrix[index_str1][index_str2] = _min2n(
                deletion,
                _min2n(
                    insertion,
                    substitution
                )
            );
        }
    }

    result = matrix[len_str1 - 1][len_str2 - 1];

    for (int index = 0; index < len_str1; index++)
        free(matrix[index]);
    free(matrix);

    return result;
}

float _simular_percentage(int distance, int len_str1, int len_str2) {
    printf(
        "%d - %d - %d\n",
        len_str1,
        len_str2,
        distance
    );
    return (len_str1 + len_str2 - distance - 0.0) / (len_str1 + len_str2 + 0.0);
}

float _search_include(char *target, char *content) {
    int len_target;
    int len_content;

    char *substring;
    int result = 0,
        tmp_num,
        index = 0;

    content = _remove_useless(content, _accepted_chars);
    target = _remove_useless(target, _accepted_chars);

    len_target = strlen(target);
    len_content = strlen(content);

    if (len_content == 0 || len_target == 0) {
        return 0;
    } else if (len_target > len_content) {
        char *tmp_str = target;
        target = content;
        content = tmp_str;

        len_target += len_content;
        len_content = len_target - len_content;
        len_target = len_target - len_content;
    }

    while (1) {
        if (!(index < len_content))
            break;
        index += len_target;

        substring = _substr(content, index - len_target, index);
        if (
            (tmp_num = _levenshtein_distance(target, substring)) < result ||
            result == 0
        )
            result = tmp_num;

        printf("%d\n", result);

        free(substring);
    }

    free(content);
    free(target);
    return _simular_percentage(result, len_target, len_content);
}

#endif /*LEVENSHTEIN_H*/
