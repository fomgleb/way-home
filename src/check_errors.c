#include "../inc/header.h"

void mx_try_print_usage_error(int argc) {
	if (argc != 6) {
		mx_error("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
    }
}

void mx_try_print_file_error(char **argv) {
	int file = open(argv[1], O_RDONLY);
	if (file == -1) {
		mx_error("map does not exist\n");
    }
	close(file);
}

void mx_try_print_str_error(char *map_str) {
	if (mx_strlen(map_str) <= 0) {
		free(map_str);
		mx_error("map does not exist\n");
	}
}

void mx_try_print_coordinates_error(t_vector2 point, t_board *board, char *map_str) {
	if (point.x < 0 || point.y < 0 || point.x >= board->size.x || point.y >= board->size.y) {
		free(map_str);
		mx_free_board(board);
		mx_error("points are out of map range\n");
	}
}

void mx_try_print_entry_obstacle_error(t_board *board, char *map_str, t_vector2 point) {
	if (board->arr[point.y][point.x].is_obstacle) {
		free(map_str);
		mx_free_board(board);
		mx_error("entry point cannot be an obstacle\n");
	}
}

void mx_try_print_exit_obstacle_error(t_board *board, char *map_str, t_vector2 point) {
    if (board->arr[point.y][point.x].is_obstacle) {
		mx_free_board(board);
		free(map_str);
        mx_error("exit point cannot be an obstacle\n");
    }
}

void mx_try_print_route_not_found_error(t_board *board, char *map_str, t_vector2 exit_point) {
	if (board->arr[exit_point.y][exit_point.x].how_far_point_is == -1) {
		mx_free_board(board);
		free(map_str);
		mx_error("route not found\n");
	}	
}

void mx_try_print_othercases_error() {
	mx_error("error\n");
}

