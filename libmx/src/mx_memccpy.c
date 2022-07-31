#include "libmx.h"

void* mx_memccpy(void* restrict dst, const void* restrict src, int c, size_t n) {
	char* str1 = (char*)dst;
	char* str2 = (char*)src;
	for (size_t i = 0; i < n; i++) {
		if (*(str2 + i) != c) {
			*(str1 + i) = *(str2 + i);
		}
		else {
			*(str1 + i) = *(str2 + i);
			return str1;
		}
	}
	return NULL;
}
