#include "postgres.h"
#include "./levenshtein_distance/levenshtein.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

Datum levenshtein(PG_FUNCTION_ARGS);
Datum fuzzering(PG_FUNCTION_ARGS);
Datum simular(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(levenshtein);
PG_FUNCTION_INFO_V1(fuzzering);
PG_FUNCTION_INFO_V1(simular);

Datum levenshtein(PG_FUNCTION_ARGS) {
    PG_RETURN_INT32(
        _levenshtein_distance(
            text_to_cstring(PG_GETARG_TEXT_P(0)),
            text_to_cstring(PG_GETARG_TEXT_P(1))
        )
    );
}

Datum fuzzering(PG_FUNCTION_ARGS) {
    PG_RETURN_FLOAT8(
        _search_include(
            text_to_cstring(PG_GETARG_TEXT_P(0)),
            text_to_cstring(PG_GETARG_TEXT_P(1))
        )
    );
}

Datum simular(PG_FUNCTION_ARGS) {
    PG_RETURN_FLOAT8(
        _simular_percentage(
            PG_GETARG_INT32(0),
            PG_GETARG_INT32(1),
            PG_GETARG_INT32(2)
        )
    );
}
