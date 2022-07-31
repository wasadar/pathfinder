#include "libmx.h"

void* mx_memmem(const void* big, size_t big_len, const void* little, size_t little_len) {
	void* temp = (void*)big;
	bool check;
	for (size_t i = 0; i < big_len - little_len; i++) {
		if (!mx_memcmp(temp,little,little_len)) {
			return temp;
		}
		temp++;
	}
	return NULL;
}
