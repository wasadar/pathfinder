#include "libmx.h"

char* mx_del_extra_spaces(const char* str) {
	if (!str) {
		return NULL;
	}
	bool check = true;
	int res_len = 0;
	for (int i = 0; i < mx_strlen(str); i++) {
		if ((*(str + i) != '\b') && (*(str + i) != '\t') && (*(str + i) != '\n') && (*(str + i) != '\v') && (*(str + i) != '\f') && (*(str + i) != '\r') && (*(str + i) != ' ')) {
			if (res_len != 0) {
				if (check == false) {
					res_len++;
				}
			}
			res_len++;
			check = true;
		}
		else if (check) {
			check = false;
		}
	}
	if (res_len == 0) {
		return NULL;
	}
	char* res = mx_strnew(res_len);
	if (!res) {
		return NULL;
	}
	int count = 0;
	check = true;
	for (int i = 0; i < mx_strlen(str); i++) {
		if ((*(str + i) != '\b') && (*(str + i) != '\t') && (*(str + i) != '\n') && (*(str + i) != '\v') && (*(str + i) != '\f') && (*(str + i) != '\r') && (*(str + i) != ' ')) {
			if (count != 0) {
				if (check == false) {
					*(res + count) = ' ';
					count++;
				}
			}
			*(res + count) = *(str + i);
			count++;
			check = true;
		}
		else if (check) {
			check = false;
		}
		if (count == res_len) {
			break;
		}
	}
	return res;
}
