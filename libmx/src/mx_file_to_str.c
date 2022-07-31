#include "libmx.h"

char* mx_file_to_str(const char* file) {
	int f = open(file, O_RDONLY);
	if (f == 0) {
		return NULL;
	}
	int buflen = 8000;
	char* buf = (char*)malloc(sizeof(char) * buflen + 1);
	if (!buf) {
		return NULL;
	}
	*(buf + buflen) = '\0';
	char* res = NULL;
	char* temp = NULL;
	int rd = 1;
	while (rd > 0) {
		rd = read(f, buf, buflen);
		if (rd == -1) {
			if (temp) {
				free(temp);
			}
			if (res) {
				free(res);
			}
			free(buf);
			return NULL;
		}
		*(buf + rd) = '\0';
		temp = res;
		res = mx_strjoin(buf, temp);
		if (temp) {
			free(temp);
		}
		if (!res) {
			free(buf);
			return NULL;
		}
	}
	close(f);
	free(buf);
	return res;
}
