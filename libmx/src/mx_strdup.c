#include "libmx.h"

char* mx_strdup(const char* str) {
	char* res = mx_strnew(mx_strlen(str));
	if (res) {
		res = mx_strcpy(res, str);
	}
	return res;
}
