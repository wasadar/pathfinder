#include "pathfinder.h"

int count_shortest_way_len(loen* edges, logv* graphs, gv* start) {
	gv* temp = start;
	start->weight = 0;
	loen* ways = edges;
	logv* points = graphs;
	while (true) {
		ways = edges;
		while (ways != NULL) {
			if (is_connected(ways, temp)) {
				if (!get_other(ways, temp)->is_checked) {
					if (get_other(ways, temp)->weight > temp->weight + ways->len) {
						get_other(ways, temp)->weight = temp->weight + ways->len;
					}
				}
			}
			ways = ways->next;
		}
		temp->is_checked = true;
		points = graphs;
		while (points != NULL) {
			if (points->data->is_checked == false) {
				if (temp->is_checked == true) {
					temp = points->data;
				}
				else if (points->data->weight < temp->weight) {
					temp = points->data;
				}
			}
			points = points->next;
		}
		if (temp->is_checked) {
			break;
		}
	}
	points = graphs;
	while(points != NULL){
		points->data->is_checked = false;
		points = points->next;
	}
	return 0;
}
