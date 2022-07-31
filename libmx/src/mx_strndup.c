#include "libmx.h"

char* mx_strndup(const char* str, size_t n) {
	char* res;
	if ((size_t)mx_strlen(str) < n) {
		res = mx_strnew(mx_strlen(str));
	}
	else {
		res = mx_strnew(n);
	}
	if (res) {
		res = mx_strncpy(res, str, n);
	}
	return res;
}
