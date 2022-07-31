#include "pathfinder.h"

int create_node(char* nm1, char* nm2, int len, loen* edges, logv* graphs, int islands) {
	if (!mx_strcmp(nm1,nm2)){
		delete_lists(edges, graphs);
		return 5;
	}
	loen* tmp1 = NULL;
	logv* tmp2 = NULL;
	bool check = false;
	bool end_check = false;
	bool edg_check = false;
	int count;
	if (edges->len != -1) {
		edg_check = true;
		tmp1 = (loen*)malloc(sizeof(loen));
	}
	else {
		tmp1 = edges;
	}
	tmp1->next = NULL;
	tmp1->len = len;
	if (graphs->next == NULL) {
		graphs->data = (gv*)malloc(sizeof(gv));
		graphs->data->name = nm1;
		graphs->data->is_checked = false;
		graphs->data->gic = false;
		graphs->data->weight = 2147483647;
		graphs->next = (logv*)malloc(sizeof(logv));
		graphs->next->data = (gv*)malloc(sizeof(gv));
		graphs->next->data->name = nm2;
		graphs->next->data->is_checked = false;
		graphs->next->data->gic = false;
		graphs->next->data->weight = 2147483647;
		graphs->next->next = NULL;
	}
	tmp2 = graphs;
	count = 0;
	while (tmp2 != NULL) {
		if (!mx_strcmp(tmp2->data->name, nm1)) {
			tmp1->start = tmp2->data;
			check = true;
		}
		if (!mx_strcmp(tmp2->data->name, nm2)) {
			tmp1->end = tmp2->data;
			end_check = true;
		}
		tmp2 = tmp2->next;
		count++;
	}
	if (!check) {
		if (count + 1 > islands) {
			free(nm1);
			if (!end_check) {
				free(nm2);
			}
			delete_lists(edges, graphs);
			printerr("error: invalid number of islands\n");
			return 1;
		}
		tmp2 = graphs;
		while (tmp2->next != NULL) {
			tmp2 = tmp2->next;
		}
		tmp2->next = (logv*)malloc(sizeof(logv));
		tmp2->next->data = (gv*)malloc(sizeof(gv));
		tmp2->next->data->name = nm1;
		tmp2->next->data->is_checked = false;
		tmp2->next->data->gic = false;
		tmp2->next->data->weight = 2147483647;
		tmp2->next->next = NULL;
		tmp1->start = tmp2->next->data;
		count++;
	}
	if (!end_check) {
		if (count + 1 > islands) {
			free(nm2);
			delete_lists(edges, graphs);
			printerr("error: invalid number of islands\n");
			return 1;
		}
		tmp2 = graphs;
		while (tmp2->next != NULL) {
			tmp2 = tmp2->next;
		}
		tmp2->next = (logv*)malloc(sizeof(logv));
		tmp2->next->data = (gv*)malloc(sizeof(gv));
		tmp2->next->data->name = nm2;
		tmp2->next->data->is_checked = false;
		tmp2->next->data->gic = false;
		tmp2->next->data->weight = 2147483647;
		tmp2->next->next = NULL;
		tmp1->end = tmp2->next->data;
		count++;
	}
	if (edg_check) {
		loen* temp = edges;
		while (temp->next != NULL) {
			if (((!mx_strcmp(temp->start->name, nm1)) && (!mx_strcmp(temp->end->name, nm2))) || ((!mx_strcmp(temp->start->name, nm2)) && (!mx_strcmp(temp->end->name, nm1)))) {
				delete_lists(edges, graphs);
				printerr("error: duplicate bridges\n");
				return 2;
			}
			temp = temp->next;
		}
		if (((!mx_strcmp(temp->start->name, nm1)) && (!mx_strcmp(temp->end->name, nm2))) || ((!mx_strcmp(temp->start->name, nm2)) && (!mx_strcmp(temp->end->name, nm1)))) {
			delete_lists(edges, graphs);
			printerr("error: duplicate bridges\n");
			return 2;
		}
		temp->next = tmp1;
	}
	return 0;
}
