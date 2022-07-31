#include "pathfinder.h"

void find_shortest_way(loen* edges, logv* graphs, gv* temp, gv* end, gv* start, char* way, char* len) {
	loen* ways = edges;
	logv* points = graphs;
	char* tway = NULL;
	char* tlen = NULL;
	while (points != NULL){
		ways = edges;
		while (ways != NULL){
			if (is_connected(ways, temp) && is_connected(ways, points->data) && (mx_strcmp(temp->name,points->data->name))) {
				if (is_connected(ways, end) && (temp->weight + ways->len == end->weight)) {
					if (!mx_strcmp(temp->name, start->name)) {
						print_straight_path(end, start, ways->len);
					}
					else {
						print_not_straight_path(temp, end, start, way, len, ways->len);
					}
				}
				else if (temp->weight + ways->len == get_other(ways, temp)->weight) {
					if (!mx_strcmp(temp->name, start->name)) {
						tway = write_way(start);
						tlen = write_len(ways->len);
					}
					else {
						tway = change_way(temp, way);
						tlen = change_len(ways->len, len);
					}
					find_shortest_way(edges, graphs, get_other(ways, temp), end, start, tway, tlen);
					free(tway);
					tway = NULL;
					free(tlen);
					tlen = NULL;
				}
			}
			ways = ways->next;
		}
		points = points->next;
	}
}
