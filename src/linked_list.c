#include "../inc/header.h"

t_list *mx_create_node(t_vector2 coordinates) {
	t_list *node = malloc(sizeof(t_list));
	node->coordinates = coordinates;
	node->next = NULL;
	return node;
}

void mx_push_back(t_list **list, t_vector2 coordinates) {
	t_list *new_node = mx_create_node(coordinates);
	t_list *last_node = *list;
	if (last_node != NULL) {
		for ( ; last_node->next != NULL; last_node = last_node->next) { }
		last_node->next = new_node;
	} else {
		*list = new_node;
	}
}

void mx_pop_front(t_list **list) {
	t_list *second_node = (*list)->next;
	free(*list);
	*list = NULL;
	if (second_node != NULL)
		*list = second_node;
}

