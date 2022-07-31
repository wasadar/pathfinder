#include "libmx.h"

void* mx_memcpy(void* restrict dst, const void* restrict src, size_t n) {
	char* str1 = (char*)dst;
	char* str2 = (char*)src;
	for (size_t i = 0; i < n; i++) {
		*(str1 + i) = *(str2 + i);
	}
	return dst;
}
