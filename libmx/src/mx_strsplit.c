#include "libmx.h"

char** mx_strsplit(const char* s, char c) {
	if (s == NULL) {
		return NULL;
	}
	int count = mx_count_words(s, c);
	if (count == 0) {
		return NULL;
	}
	char** res = (char**)malloc(sizeof(char*) * (count + 1));
	if (!res) {
		return NULL;
	}
	*(res + count) = NULL;
	bool check = true;
	int strlen = 0;
	int temp = 0;
	for (int i = 0; i < mx_strlen(s); i++) {
		if ((*(s + i) != c) && check) {
			while (*(s + i + strlen) != c) {
				if (*(s + i + strlen) == '\0') {
					break;
				}
				strlen++;
			}
			if (temp == count){
				for (int i = 0; i < temp; i++) {
					free(*(res + i));
				}
				free(res);
				return NULL;
			}
			*(res + temp) = mx_strndup((s + i), strlen);
			if (*(res + temp) == NULL) {
				for (int i = 0; i < temp; i++) {
					free(*(res + i));
				}
				free(res);
				return NULL;
			}
			temp++;
			strlen = 0;
			check = false;
		}
		else if (*(s + i) == c) {
			check = true;
		}
	}
	return res;
}
