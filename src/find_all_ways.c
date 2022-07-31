#include "pathfinder.h"

void find_all_ways(loen* edges, logv* graphs) {
	char* way = NULL;
	char* len = NULL;
	logv* points;
	logv* check;
	check = graphs;
	while (check != NULL) {
		count_shortest_way_len(edges, graphs, check->data);
		points = graphs;
		while (points != NULL) {
			if ((mx_strcmp(points->data->name,check->data->name)) && (!points->data->gic)) {
				find_shortest_way(edges, graphs, check->data, points->data, check->data, way, len);
			}
			points = points->next;
		}
		check->data->gic = true;
		check = check->next;
		points = graphs;
		while(points != NULL){
			points->data->weight = 2147483647;
			points = points->next;
		}
	}
	delete_lists(edges,graphs);
}
