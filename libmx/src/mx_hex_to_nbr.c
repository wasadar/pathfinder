#include "libmx.h"

unsigned long mx_hex_to_nbr(const char* hex){
	unsigned long res = 0;
	int i = 0;
	while (*(hex + i)) {
		if ((*(hex + i) <= 57) && (*(hex + i) >= 48)) {
			res *= 16;
			res += (*(hex + i) - 48);
		}
		else if ((*(hex + i) <= 70) && (*(hex + i) >= 65)) {
			res *= 16;
			res += (*(hex + i) - 55);
		}
		else if ((*(hex + i) <= 102) && (*(hex + i) >= 97)) {
			res *= 16;
			res += (*(hex + i) - 87);
		}
		else {
			break;
		}
		i++;
	}
	return res;
}
