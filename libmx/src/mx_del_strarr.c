#include "libmx.h"

void mx_del_strarr(char*** arr) {
	char** temp = *arr;
	while (temp != NULL) {
		free(*temp);
		temp++;
	}
	temp = *arr;
	free(temp);
	*arr = NULL;
}
