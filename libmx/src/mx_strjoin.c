#include "libmx.h"

char* mx_strjoin(const char* s1, const char* s2) {
	if ((!s1) && (!s2)) {
		return NULL;
	}
	else if (!s1) {
		return mx_strdup(s2);
	}
	else if (!s2) {
		return mx_strdup(s1);
	}
	else {
		char* res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		if (!res) {
			return NULL;
		}
		*res = '\0';
		mx_strcat(res, s1);
		mx_strcat(res, s2);
		return res;
	}
}
