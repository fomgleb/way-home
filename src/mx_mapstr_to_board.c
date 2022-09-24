#include "../inc/header.h"

t_vector2 mx_get_map_size(const char *map) {
	t_vector2 map_size = {0, 0};
	for (int i = 0; map[i] != '\n'; ++i) {
		if (map[i] != ',')
			map_size.x++;
	}
	int temp_map_width = 0;
	for (int i = 0; map[i] != '\0'; ++i) {
		if (map[i] == '\n') {
			map_size.y++;
			if (temp_map_width != map_size.x) {
				free((char *)map);
				mx_error("map error\n");
			}
			temp_map_width = 0;
		} else if (map[i] == '#' || map[i] == '.') {
			temp_map_width++;
		} else if (map[i] != ','){
			free((char *)map);
			mx_error("map error\n");
		}
	}
	return map_size;
}

t_board mx_mapstr_to_board(char *map) {
	t_board board = {NULL, {0, 0}};
	board.size = mx_get_map_size(map);
	board.arr = malloc(board.size.y * sizeof(t_point *));
	for (int i = 0; i < board.size.y; ++i) {
		board.arr[i] = malloc(board.size.x * sizeof(t_point));
	}

	int x = 0;
	int y = 0;
	for (int i = 0; y < board.size.y; ++i) {
		if (map[i] == '#') {
			board.arr[y][x].how_far_point_is = -1;
			board.arr[y][x].is_obstacle = true;
			board.arr[y][x].is_way = false;
			x++;
		} else if (map[i] == '.') {
			board.arr[y][x].how_far_point_is = -1;
			board.arr[y][x].is_obstacle = false;
			board.arr[y][x].is_way = false;
			x++;
		} else if (map[i] == ',') {
			continue;
		} else if (map[i] == '\n') {
			y++;
			x = 0;
		} else {
			mx_error("map error\n");
		}
	}
	return board;
}

