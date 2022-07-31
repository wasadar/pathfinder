#include "pathfinder.h"

void preparation_of_pointers(loen* edges, logv* graphs) {
	edges->next = NULL;
	edges->len = -1;
	graphs->next = NULL;
}
