#include "libmx.h"

int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd) {
	char* temp = *(lineptr);
	int tmp = 1;
	int count = 0;
	while (tmp > 0) {
		tmp = read(fd, temp, buf_size);
		for (int i = 0; i < tmp; i++) {
			count++;
			if (*temp == delim) {
				*(temp + 1) = '\0';
				return count;
			}
			else {
				temp++;
			}
		}
	}
	if (tmp == 0) {
		return -1;
	}
	else {
		return -2;
	}
}
