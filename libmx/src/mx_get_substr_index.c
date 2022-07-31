#include "libmx.h"

int mx_get_substr_index(const char* str, const char* sub) {
	if (str && sub) {
		int l1 = mx_strlen(str);
		int l2 = mx_strlen(sub);
		bool check;
		for (int i = 0; i < l1 - l2; i++) {
			check = true;
			for (int j = 0; j < l2; j++) {
				if (*(str + i + j) != *(sub + j)) {
					check = false;
					break;
				}
			}
			if (check) {
				return i;
			}
		}
		return -1;
	}
	else {
		return -2;
	}
}
