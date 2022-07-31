#include "pathfinder.h"

char* change_len(int l, char* len) {
	char* t1 = mx_itoa(l);
	char* t2 = mx_strjoin(len, " + ");
	char* t3 = mx_strjoin(t2, t1);
	free(t1);
	free(t2);
	return t3;
}
