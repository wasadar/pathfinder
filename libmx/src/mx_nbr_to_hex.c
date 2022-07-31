#include "libmx.h"

char* mx_nbr_to_hex(unsigned long nbr) {
	if (nbr == 0) {
		char* res = mx_strnew(1);
		*res = '0';
		return res;
	}
	else {
		unsigned long temp = nbr;
		int count = 0;
		while (temp > 0) {
			temp /= 16;
			count++;
		}
		char* res = mx_strnew(count);
		temp = nbr;
		for (int i = count - 1; i >= 0; i--) {
			if (temp % 16 >= 10) {
				*(res + i) = temp % 16 + 87;
			}
			else {
				*(res + i) = temp % 16 + 48;
			}
			temp /= 16;
		}
		return res;
	}
}

