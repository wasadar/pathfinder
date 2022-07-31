#include "pathfinder.h"

void print_straight_path(gv* end, gv* start, int l) {
	mx_printstr("========================================\n");
	char* t1 = mx_strjoin("Path: ", start->name);
	char* t2 = mx_strjoin(t1, " -> ");
	free(t1);
	t1 = mx_strjoin(t2, end->name);
	free(t2);
	t2 = mx_strjoin(t1, "\n");
	free(t1);
	mx_printstr(t2);
	free(t2);
	t1 = mx_strjoin("Route: ", start->name);
	t2 = mx_strjoin(t1, " -> ");
	free(t1);
	t1 = mx_strjoin(t2, end->name);
	free(t2);
	t2 = mx_strjoin(t1, "\n");
	free(t1);
	mx_printstr(t2);
	free(t2);
	t1 = mx_itoa(l);
	t2 = mx_strjoin("Distance: ", t1);
	free(t1);
	t1 = mx_strjoin(t2, "\n");
	free(t2);
	mx_printstr(t1);
	free(t1);
	mx_printstr("========================================\n");
}
