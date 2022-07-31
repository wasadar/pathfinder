#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len){
    int i = 0;
    while (*(src + i) != '\0'){
        *(dst + i) = *(src + i);
        i++;
        if (i == len) {
            break;
        }
    }
    return dst;
}
