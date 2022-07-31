#include "libmx.h"

void mx_print_strarr(char** arr, const char* delim) {
	int i = 0;
	while (*(arr + i) != NULL) {
		if (i != 0) {
			mx_printchar(*delim);
		}
		mx_printstr(*(arr + i));
	}
	mx_printchar('\n');
}
