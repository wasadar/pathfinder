#include "pathfinder.h"

int my_atoi(char* str) {
	int i = 0;
	int res = 0;
	while (*(str + i) != '\0') {
		res *= 10;
		if ((*(str + i) >= 48) && (*(str + i) <= 57)) {
			res += *(str + i) - 48;
		}
		else {
			return -1;
		}
		i++;
	}
	return res;
}
