#include "pathfinder.h"

void print_not_straight_path(gv* temp, gv* end, gv* start, char* way, char* len, int l) {
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
	t1 = mx_strjoin("Route: ", way);
	t2 = mx_strjoin(t1, " -> ");
	free(t1);
	t1 = mx_strjoin(t2, temp->name);
	free(t2);
	t2 = mx_strjoin(t1, " -> ");
	free(t1);
	t1 = mx_strjoin(t2, end->name);
	free(t2);
	t2 = mx_strjoin(t1, "\n");
	mx_printstr(t2);
	free(t2);
	t1 = mx_strjoin("Distance: ", len);
	t2 = mx_strjoin(t1, " + ");
	free(t1);
	t1 = mx_strjoin(t2, mx_itoa(l));
	free(t2);
	t2 = mx_strjoin(t1, " = ");
	free(t1);
	t1 = mx_strjoin(t2, mx_itoa(end->weight));
	free(t2);
	t2 = mx_strjoin(t1, "\n");
	free(t1);
	mx_printstr(t2);
	free(t2);
	mx_printstr("========================================\n");
}
