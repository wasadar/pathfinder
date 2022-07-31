#include "pathfinder.h"

int main(int argc, char* argv[]) {
	char* data = NULL;
	char** file = NULL;
	loen* edges = malloc(sizeof(loen));
	logv* graphs = malloc(sizeof(logv));
	preparation_of_pointers(edges, graphs);
	int i = 0;
	if (argc != 2) {
		printerr("usage: ./pathfinder [filename]\n");
	}
	else {
		data = read_file(argv[1]);
		if (data != NULL) {
			if (check_data(data)) {
				file = mx_strsplit(data, '\n');
				free(data);
				data = NULL;
				if (parse_file(file, edges, graphs) == 0) {
					while(*(file + i) != NULL){
						free(*(file + i));
						i++;
					}
					free(file);
					file = NULL;
					find_all_ways(edges, graphs);
					return 0;
				}
				while(*(file + i) != NULL){
					free(*(file + i));
					i++;
				}
				free(file);
				file = NULL;
			}
			else {
				free(data);
			}
		}
	}
	return -1;
}
