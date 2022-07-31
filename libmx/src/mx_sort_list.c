#include "libmx.h"

t_list* mx_sort_list(t_list* lst, bool(*cmp)(void*, void*)) {
	t_list* temp = mx_create_node("t");
	temp->next = lst;
	t_list* tmp = temp;
	t_list* swap;
	bool check = true;
	while (check) {
		check = false;
		temp = tmp;
		for (int i = 0; i < mx_list_size(lst) - 2; i++) {
			if (cmp(temp->next->data, temp->next->next->data)) {
				swap = temp->next;
				temp->next = temp->next->next;
				swap->next = temp->next->next->next;
				temp->next->next->next = swap;
				check = true;
			}
			temp = temp->next;
		}
	}
	lst = tmp->next;
	free(tmp);
	return lst;
}
