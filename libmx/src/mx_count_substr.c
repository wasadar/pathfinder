#include "libmx.h"

int mx_count_substr(const char* str, const char* sub) {
	if (str && sub){
		if (*sub == '\0') {
			return 0;
		}
		int l1 = mx_strlen(str);
		int l2 = mx_strlen(sub);
		int count = 0;
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
				count++;
			}
		}
		return count;
	}
	else {
		return -1;
	}
}
