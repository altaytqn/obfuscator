#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_utils.h"

char* c_obf_csharp(const char* code) {
    if(!code) return NULL;
    size_t length = strlen(code)*4 + 1024;
    char* out = (char*)malloc(length);
    if(!out) return NULL;
    out[0] = '\0';
    const char* cursor = code;
    while(*cursor) {
        const char* line_end = strchr(cursor, '\n');
        if(!line_end) line_end = cursor + strlen(cursor);
        int len = (int)(line_end - cursor);
        char* line = (char*)malloc(len+1);
        strncpy(line, cursor, len);
        line[len] = '\0';
        char* splitted = mix_hashes(line);
        char* e = base64_encode(splitted);
        strcat(out, "/*CS_C:");
        strcat(out, e);
        strcat(out, "*/\n");
        free(e);
        free(splitted);
        free(line);
        if(*line_end == '\n') line_end++;
        cursor = line_end;
    }
    return out;
}
