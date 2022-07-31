#include "pathfinder.h"

void delete_lists(loen* edges, logv* graphs) {
	delete_loen(edges);
	delete_logv(graphs);
}
