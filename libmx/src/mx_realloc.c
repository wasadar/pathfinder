#include "libmx.h"

void* mx_realloc(void* ptr, size_t size) {
	char* str1 = (char*)ptr;
	void* res = malloc(size);
	char* str2 = (char*)res;
	mx_memcpy(str1, str2, size);
	free(ptr);
	ptr = res;
	return res;
}
