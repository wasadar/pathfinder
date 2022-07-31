#include "pathfinder.h"

int parse_file(char** file, loen* edges, logv* graphs) {
	int count = my_atoi(*file);
	int i = 1;
	bool check = true;
	loen* ways = NULL;
	logv* points = NULL;
	long sum = 0;
	if (count == -1) {
		printerr("error: line 1 is not valid\n");
		check = false;
	}
	else {
		if (*(file + 1) == NULL){
			printerr("error: line ");
			printerr(mx_itoa(i + 1));
			printerr(" is not valid\n");
			free(edges);
			free(graphs);
			check = false;
		}
		while (*(file + i) != NULL) {
			int tmp = parse_line(*(file + i), edges, graphs, count);
			if (tmp != 0) {
				if (tmp == 5) {
					printerr("error: line ");
					printerr(mx_itoa(i + 1));
					printerr(" is not valid\n");
				}
				check = false;
				break;
			}
			i++;
		}
	}
	if (check) {
		points = graphs;
		i = 0;
		while(points != NULL){
			i++;
			points = points->next;
		}
		if  (i != count){
			delete_lists(edges, graphs);
			printerr("error: invalid number of islands\n");
			return 10;
		}
		ways = edges;
		while(ways != NULL){
			sum += ways->len;
			if (sum > INT_MAX){
				printerr("error: sum of bridges lengths is too big\n");
				delete_lists(edges,graphs);
				return 10;
			}
			ways = ways->next;
		}
		return 0;
	}
	else {
		return 10;
	}
}
