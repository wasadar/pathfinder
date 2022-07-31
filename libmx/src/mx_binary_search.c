#include "libmx.h"

int mx_binary_search(char** arr, int size, const char* s, int* count) {
	int start = -1;
	int end = size;
	int middle = 0;
	*count = 0;
	while (start <= end) {
		*count += 1;
		if (middle != start + ((end - start) / 2)) {
			middle = start + ((end - start) / 2);
		}
		else {
			middle = middle + 1;
		}
		if (mx_strcmp(s, *(arr + middle)) == 0) {
			return middle;
		}
		else if (mx_strcmp(s, *(arr + middle)) < 0) {
			end = middle;
		}
		else if (mx_strcmp(s, *(arr + middle)) > 0) {
			start = middle;
		}
		if (start == end - 1) {
			*count = 0;
			return -1;
		}
	}
	*count = 0;
	return -1;
}
