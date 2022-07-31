#include "libmx.h"

t_list* mx_create_node(void* data) {
	t_list* res = malloc(sizeof(t_list));
	res->next = NULL;
	res->data = data;
	return res;
}
