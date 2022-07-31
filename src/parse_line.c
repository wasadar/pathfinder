#include "pathfinder.h"

int parse_line(char* line, loen* edges, logv* graphs, int islands) {
	if (is_valid(line)) {
		size_t i = 0;
		while (*(line + i) != '-') {
			i++;
		}
		if (i == 0){
			delete_lists(edges,graphs);
			return 5;
		}
		char* nm1 = mx_strndup(line, i);
		i++;
		size_t t = i;
		i = 0;
		while (*(line + t + i) != ',') {
			i++;
		}
		if (i == 0){
			delete_lists(edges,graphs);
			free(nm1);
			return 5;
		}
		char* nm2 = mx_strndup((line + t), i);
		t++;
		t += i;
		char* len = mx_strdup((line + t));
		if (my_atoi(len) > 0) {
			int res = create_node(nm1, nm2, my_atoi(len), edges, graphs, islands);
			free(len);
			return res;
		}
		else {
			delete_lists(edges,graphs);
			free(nm1);
			free(nm2);
			free(len);
			return 5;
		}
	}
	else {
		return 5;
	}
}
