#include "libmx.h"

void* mx_memrchr(const void* s, int c, size_t n) {
	char* str = (char*)s + mx_strlen(s);
	for (size_t i = 0; i < n; i++) {
		str--;
		if (*str == c) {
			return str;
		}
	}
	return NULL;
}
