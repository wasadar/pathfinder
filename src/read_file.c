#include "pathfinder.h"

char* read_file(char* name) {
	int file = open(name, O_RDONLY);
	if (file == -1) {
		printerr("error: file ");
		printerr(name);
		printerr(" does not exist\n");
		return NULL;
	}
	else {
		char buf[8001];
		int rd = 8000;
		char* res = NULL;
		char* temp = NULL;
		while (rd == 8000) {
			rd = read(file, buf, 8000);
			if (rd == 0) {
				printerr("error: file ");
				printerr(name);
				printerr(" is empty\n");
				free(res);
				free(temp);
				return NULL;
			}
			*(buf + rd) = '\0';
			temp = res;
			res = mx_strjoin(res, buf);
			if (temp != NULL) {
				free(temp);
			}
		}
		return res;
	}
	return NULL;
}
