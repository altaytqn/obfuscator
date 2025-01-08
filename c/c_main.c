#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* c_obf_python(const char*);
extern char* c_obf_cpp(const char*);
extern char* c_obf_csharp(const char*);

static char* read_multiline() {
    size_t size = 4096;
    char* buf = (char*)malloc(size);
    if(!buf) return NULL;
    buf[0] = '\0';
    size_t used = 0;
    while(!feof(stdin)) {
        if(used+2 >= size) {
            size *= 2;
            char* nb = (char*)realloc(buf, size);
            if(!nb) {
                free(buf);
                return NULL;
            }
            buf = nb;
        }
        int c = fgetc(stdin);
        if(c == EOF) break;
        buf[used++] = (char)c;
        buf[used] = '\0';
    }
    return buf;
}

int main() {
    printf("====================================\n");
    printf("   C OBFUSCATOR MAIN MENU\n");
    printf("====================================\n");
    printf("1) Obfuscate Python\n");
    printf("2) Obfuscate C++\n");
    printf("3) Obfuscate C#\n");
    printf("Enter choice: ");
    char line[8];
    fgets(line, sizeof(line), stdin);
    int choice = atoi(line);
    printf("Paste your code (Ctrl+D/Z to finish):\n");
    char* input = read_multiline();
    if(!input) {
        printf("Failed to read code.\n");
        return 1;
    }
    char* result = NULL;
    if(choice == 1) result = c_obf_python(input);
    else if(choice == 2) result = c_obf_cpp(input);
    else if(choice == 3) result = c_obf_csharp(input);
    if(result) {
        printf("----- OBFUSCATED CODE -----\n%s\n", result);
        free(result);
    } else {
        printf("No output.\n");
    }
    free(input);
    return 0;
}
