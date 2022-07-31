#include "libmx.h"

int mx_quicksort(char** arr, int left, int right) {
	int count = 0;
	if (right > left) {
		int r = right, l = left;
		char* str = *(arr + ((r + l) / 2));
		while (l > r) {
			while ((mx_strcmp(*(arr + l), str) < 0) && (l < r)){
				l++;
			}
			if (l != r) {
				char* tmp = *(arr + l);
				*(arr + l) = *(arr + r);
				*(arr + r) = tmp;
				count++;
				l++;
			}
			while ((mx_strcmp(*(arr + r), str) > 0) && (l < r)) {
				r--;
			}
			if (l != r) {
				char* tmp = *(arr + l);
				*(arr + l) = *(arr + r);
				*(arr + r) = tmp;
				count++;
				r--;
			}
		}
		count += mx_quicksort(arr, left, r);
		count += mx_quicksort(arr, l, right);
	}
	return count;
}
