#include "pathfinder.h"

char* change_way(gv* temp,char* way) {
	char* t1 = mx_strjoin(way, " -> ");
	char* t2 = mx_strjoin(t1, temp->name);
	free(t1);
	return t2;
}
