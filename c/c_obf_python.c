#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_utils.h"

char* c_obf_python(const char* code) {
    if(!code) return NULL;
    const char* ptr = code;
    size_t len = strlen(code) * 4 + 1024;
    char* out = (char*)malloc(len);
    if(!out) return NULL;
    out[0] = '\0';
    while(*ptr) {
        const char* eol = strchr(ptr, '\n');
        if(!eol) eol = ptr + strlen(ptr);
        int segment_len = (int)(eol - ptr);
        char* segment = (char*)malloc(segment_len + 1);
        strncpy(segment, ptr, segment_len);
        segment[segment_len] = '\0';
        char* shuffled = shuffle_str(segment);
        char* b64 = base64_encode(shuffled);
        strcat(out, "#PY_C:");
        strcat(out, b64);
        strcat(out, "\n");
        free(shuffled);
        free(b64);
        free(segment);
        if(*eol == '\n') eol++;
        ptr = eol;
    }
    return out;
}
