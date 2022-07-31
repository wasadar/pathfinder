#include "pathfinder.h"

void delete_loen(loen* edges) {
	loen* temp = NULL;
	while (edges != NULL) {
		temp = edges;
		edges = edges->next;
		free(temp);
	}
	edges = NULL;
}
