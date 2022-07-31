#include "pathfinder.h"

gv* get_other(loen* edge, gv* vertex) {
	if (is_connected(edge,vertex)) {
		if (!mx_strcmp(edge->start->name,vertex->name)) {
			return edge->end;
		}
		else if (!mx_strcmp(edge->end->name,vertex->name)){
			return edge->start;
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}
