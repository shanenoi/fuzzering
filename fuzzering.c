// Copyright 2021 Shanenoi

#include "postgres.h"
#include "./levenshtein_distance/levenshtein.h"
#include "fmgr.h"
#include "utils/builtins.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

Datum levenshtein(PG_FUNCTION_ARGS);
Datum fuzzering(PG_FUNCTION_ARGS);
Datum simular(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(levenshtein);
PG_FUNCTION_INFO_V1(fuzzering);
PG_FUNCTION_INFO_V1(simular);

Datum levenshtein(PG_FUNCTION_ARGS) {
    char* string_a = text_to_cstring(PG_GETARG_TEXT_P(0));
    char* string_b = text_to_cstring(PG_GETARG_TEXT_P(1));
    PG_RETURN_INT32(_search_include(string_a, string_b));
}

Datum fuzzering(PG_FUNCTION_ARGS) {
    char* string_a = text_to_cstring(PG_GETARG_TEXT_P(0));
    char* string_b = text_to_cstring(PG_GETARG_TEXT_P(1));
    PG_RETURN_FLOAT8(_search_include(string_a, string_b));
}

Datum simular(PG_FUNCTION_ARGS) {
    int32 number_a = PG_GETARG_INT32(0);
    int32 number_b = PG_GETARG_INT32(1);
    int32 number_c = PG_GETARG_INT32(2);
    PG_RETURN_FLOAT8(_simular_percentage(number_a, number_b, number_c));
}
