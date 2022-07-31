#pragma once
#include "libmx.h"
#include <limits.h>

typedef struct list_of_edges_node loen;
typedef struct graph_vertex gv;
typedef struct list_of_graph_vertices logv;

struct list_of_edges_node {
	gv* start;
	gv* end;
	int len;
	loen* next;
};

struct graph_vertex {
	char* name;
	bool is_checked;
	bool gic;
	int weight;
};

struct list_of_graph_vertices {
	gv* data;
	logv* next;
};

enum results {
	err_inv_num = -1,
	correct = 0,
	err_num = 1,
	err_dup = 2,
	err_sum = 3,
	err_file = 4,
	err_line = 5
};

int create_node(char* nm1, char* nm2, int len, loen* edges, logv* graphs, int islands);
void delete_lists(loen* edges, logv* graphs);
void delete_loen(loen* edges);
void delete_logv(logv* graphs);
void delete_gv(gv* vertex);
int my_atoi(char* str);
bool is_connected(loen* edge, gv* vertex);
bool is_valid(char* line);
int parse_line(char* line, loen* edges, logv* graphs, int islands);
int parse_file(char** file, loen* edges, logv* graphs);
char* read_file(char* name);
int count_shortest_way_len(loen* edges, logv* graphs, gv* start);
gv* get_other(loen* edge, gv* vertex);
void find_shortest_way(loen* edges, logv* graphs, gv* temp, gv* end, gv* start, char* way, char* len);
void print_straight_path(gv* end, gv* start, int l);
void print_not_straight_path(gv* temp, gv* end, gv* start, char* way, char* len, int l);
char* write_way(gv* start);
char* write_len(int l);
char* change_way(gv* temp, char* way);
char* change_len(int l, char* len);
void find_all_ways(loen* edges, logv* graphs);
void preparation_of_pointers(loen* edges, logv* graphs);
bool check_data(char* data);
void printerr(const char* s);
bool my_isalpha(int c);
