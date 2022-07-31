#include "libmx.h"

char* mx_itoa(int number) {
	int temp = number;
	int count = 0;
	char* res;
	if (number > 0) {
		while (temp > 0) {
			temp /= 10;
			count++;
		}
		res = mx_strnew(count);
		temp = number;
		for (int i = count - 1; i >= 0; i--) {
			*(res + i) = temp % 10 + 48;
			temp /= 10;
		}
	}
	else if (number == 0) {
		res = mx_strnew(1);
		*res = 48;
	}
	else {
		while (temp < 0) {
			temp /= 10;
			count++;
		}
		res = mx_strnew(count + 1);
		temp = number;
		for (int i = count; i > 0; i--) {
			*(res + i) = (temp % 10) * (-1) + 48;
			temp /= 10;
		}
		*res = 45;
	}
	return res;
}
