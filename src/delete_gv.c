#include "pathfinder.h"

void delete_gv(gv* vertex) {
	free(vertex->name);
	free(vertex);
	vertex = NULL;
}
