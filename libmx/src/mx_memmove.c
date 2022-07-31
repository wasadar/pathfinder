#include "libmx.h"

void* mx_memmove(void* dst, const void* src, size_t len) {
	char* str1 = (char*)dst;
	char* str2 = (char*)src;
	for (size_t i = 0; i < len; i++) {
		*(str1 + i) = *(str2 + i);
	}
	return dst;
}
