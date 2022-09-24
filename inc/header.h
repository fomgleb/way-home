#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_vector2 {
	int x;
	int y;
} t_vector2;

typedef struct s_list {
	t_vector2 coordinates;
	struct s_list *next;
} t_list;

typedef struct s_point {
	int how_far_point_is;
	bool is_obstacle;
	bool is_way;
} t_point;

typedef struct s_board {
	t_point **arr;
	t_vector2 size;
} t_board;

t_list *mx_create_node(t_vector2 coordinates);
void mx_push_back(t_list **list, t_vector2 coordinates);
void mx_pop_front(t_list **list);

void mx_printerr(const char *s);

void mx_try_print_usage_error(int argc);
void mx_try_print_file_error(char **agrv);
void mx_try_print_str_error(char *map_str);
void mx_try_print_coordinates_error(t_vector2 point, t_board *board, char *map_str);
void mx_try_print_entry_obstacle_error(t_board *board, char *map_str, t_vector2 point);
void mx_try_print_exit_obstacle_error(t_board *board, char *map_str, t_vector2 point);
void mx_try_print_route_not_found_error(t_board *board, char *map_str, t_vector2 exit_point);
void mx_try_print_othercases_error();

int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);
void mx_printstr(const char *s);
void mx_error(char *msg);
t_board mx_mapstr_to_board(char *map);
void mx_spread_wave(t_board board, t_vector2 start);
int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
void mx_way_home(t_board board, t_vector2 exit);
void mx_free_board(t_board *board);
void mx_write_to_file(char *file_name, char *str);

