#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_utils.h"

char* c_obf_cpp(const char* code) {
    if(!code) return NULL;
    size_t len = strlen(code)*4 + 1024;
    char* out = (char*)malloc(len);
    if(!out) return NULL;
    out[0] = '\0';
    const char* p = code;
    while(*p) {
        const char* next = strchr(p, '\n');
        if(!next) next = p + strlen(p);
        int seg_len = (int)(next - p);
        char* seg = (char*)malloc(seg_len + 1);
        strncpy(seg, p, seg_len);
        seg[seg_len] = '\0';
        reverse_in_place(seg);
        char* ins = insert_random_symbols(seg);
        char* b64 = base64_encode(ins);
        strcat(out, "//CPP_C:");
        strcat(out, b64);
        strcat(out, "\n");
        free(seg);
        free(ins);
        free(b64);
        if(*next == '\n') next++;
        p = next;
    }
    return out;
}
