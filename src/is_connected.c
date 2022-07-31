#include "pathfinder.h"

bool is_connected(loen* edge, gv* vertex) {
	if (!mx_strcmp(edge->start->name, vertex->name)){
		return true;
	}
	else if (!mx_strcmp(edge->end->name, vertex->name)){
		return true;
	}
	else {
		return false;
	}
}
