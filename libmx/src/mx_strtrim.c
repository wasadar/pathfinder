#include "libmx.h"

char* mx_strtrim(const char* str) {
	if (!str) {
		return NULL;
	}
	int str_start = 0;
	int str_end = 0;
	bool check = false;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (check) {
			if ((*(str + i) != '\t') && (*(str + i) != '\n') && (*(str + i) != '\v') && (*(str + i) != '\f') && (*(str + i) != '\r') && (*(str + i) != ' ')) {
				str_end = i;
			}
		}
		else {
			if ((*(str + i) != '\t') && (*(str + i) != '\n') && (*(str + i) != '\v') && (*(str + i) != '\f') && (*(str + i) != '\r') && (*(str + i) != ' ')) {
				str_start = i;
				check = true;
			}
		}
	}
	int res_len = str_end + 1 - str_start;
	if (res_len == 1) {
		return NULL;
	}
	char* res = mx_strnew(res_len);
	if (!res) {
		return NULL;
	}
	for (int i = 0; i < res_len; i++) {
		*(res + i) = *(str + str_start + i);
	}
	return res;
}
