#include "libmx.h"

char* mx_replace_substr(const char* str, const char* sub, const char* replace) {
	if (str && sub && replace) {
		char* chr = (char*)malloc(sizeof(char) * 2);
		if (!chr) {
			return NULL;
		}
		*(chr + 1) = '\0';
		char* res = NULL;
		char* temp;
		bool check;
		for (int i = 0; i < mx_strlen(str); i++) {
			check = false;
			for (int j = 0; j < mx_strlen(sub); j++) {
				if (*(str + i + j) != *(sub + j)) {
					check = true;
					break;
				}
			}
			if (check) {
				temp = res;
				res = mx_strjoin(res, replace);
				if (!res) {
					if (temp) {
						free(temp);
					}
					free(chr);
					return NULL;
				}
				if (temp) {
					free(temp);
				}
				i += mx_strlen(sub);
			}
			else {
				*chr = *(str + i);
				temp = res;
				res = mx_strjoin(res, chr);
				if (!res) {
					if (temp) {
						free(temp);
					}
					free(chr);
					return NULL;
				}
				if (temp) {
					free(temp);
				}
			}
		}
		return res;
	}
	else {
		return NULL;
	}
}
