#include "libmx.h"

int mx_count_words(const char* str, char c) {
	if (str != NULL) {
		int count = 0;
		bool check = false;
		for (int i = 0; i < mx_strlen(str); i++) {
			if ((*(str + i) != c) && (!check)) {
				check = true;
				count++;
			}
			else if ((*(str + i) == c) && check) {
				check = false;
			}
		}
		return count;
	}
	else {
		return -1;
	}
}
