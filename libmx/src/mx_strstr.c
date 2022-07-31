#include "libmx.h"

char* mx_strstr(const char* haystack, const char* needle) {
	char* temp = (char*)haystack;
	int l1 = mx_strlen(haystack);
	int l2 = mx_strlen(needle);
	bool check;
	for (int i = 0; i < l1 - l2; i++) {
		check = true;
		for (int j = 0; j < l2; j++) {
			if (*(temp + j) != *(needle + j)) {
				check = false;
				break;
			}
		}
		if (check) {
			return temp;
		}
		temp++;
	}
	return NULL;
}
