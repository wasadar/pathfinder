#include "pathfinder.h"

void delete_logv(logv* graphs) {
	logv* temp = NULL;
	while (graphs != NULL) {
		temp = graphs;
		graphs = graphs->next;
		delete_gv(temp->data);
		free(temp);
	}
	graphs = NULL;
}
