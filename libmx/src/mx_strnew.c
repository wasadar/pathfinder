#include "libmx.h"

char* mx_strnew(const int size) {
	char* res = (char*)malloc(sizeof(char) * (size + 1));
	if (!res) {
		return NULL;
	}
	*(res + size) = '\0';
	return res;
}
