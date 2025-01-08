#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* base64_encode(const char* input) {
    static const char tbl[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if(!input) return NULL;
    int len = (int)strlen(input);
    int out_len = 4*((len+2)/3);
    char* output=(char*)malloc(out_len+1);
    if(!output) return NULL;
    int i=0,j=0;
    while(i<len) {
        unsigned long v=0; int pad=0;
        for(int n=0;n<3;n++){
            v<<=8;
            if(i<len) v|=(0xFF & input[i++]);
            else pad++;
        }
        output[j++]=tbl[(v>>18)&0x3F];
        output[j++]=tbl[(v>>12)&0x3F];
        output[j++]=(pad<2)?tbl[(v>>6)&0x3F]:'=';
        output[j++]=(pad<1)?tbl[v&0x3F]:'=';
    }
    output[j]='\0';
    return output;
}

void reverse_in_place(char* s) {
    if(!s) return;
    int l=(int)strlen(s);
    for(int i=0;i<l/2;i++){
        char t=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=t;
    }
}

char* shuffle_str(const char* orig) {
    if(!orig) return NULL;
    int l=(int)strlen(orig);
    char* tmp=(char*)malloc(l+1);
    if(!tmp) return NULL;
    strcpy(tmp, orig);
    for(int i=0;i<l;i++){
        int r=rand()%l;
        char t=tmp[i];
        tmp[i]=tmp[r];
        tmp[r]=t;
    }
    return tmp;
}

char* insert_random_symbols(char* s) {
    int l=(int)strlen(s);
    char* out=(char*)malloc(l*3+1);
    if(!out) return NULL;
    int idx=0;
    for(int i=0;i<l;i++){
        out[idx++]=s[i];
        if(rand()%3==0) out[idx++]='@'+(rand()%10);
    }
    out[idx]='\0';
    return out;
}

char* mix_hashes(char* s) {
    int l=(int)strlen(s);
    char* out=(char*)malloc(l*3+1);
    if(!out) return NULL;
    int o=0;
    for(int i=0;i<l;i++){
        out[o++]=s[i];
        if(rand()%2==0) {
            out[o++]='#';
        }
    }
    out[o]='\0';
    return out;
}
