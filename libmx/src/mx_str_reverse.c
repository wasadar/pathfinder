#include "libmx.h"

void mx_str_reverse(char* s) {
	int len = mx_strlen(s);
	char* temp = s;
	char* tempr = s;
	for (int i = 0; i < len - 1; i++) {
		tempr++;
	}
	for (int i = 0; i < len / 2; i++) {
		mx_swap_char(temp, tempr);
		temp++;
		tempr--;
	}
}
