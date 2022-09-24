#include "../inc/header.h"

int mx_get_max(t_board board) {
	int max = -1;
	for (int y = 0; y < board.size.y; ++y) {
		for (int x = 0; x < board.size.x; ++x) {
			if (board.arr[y][x].how_far_point_is > max)
				max = board.arr[y][x].how_far_point_is;
		}
	}
	return max;
}

void mx_free_board(t_board *board) {
	for (int i = 0; i < board->size.y; ++i) {
		free(board->arr[i]);
	}
	free(board->arr);
}

char *mx_get_path_str(t_board board, char *map_str, int dist) {
	char *path = mx_strnew(mx_strlen(map_str));
	int path_len = 0;
	for (int y = 0; y < board.size.y; ++y) {
		for (int x = 0; x < board.size.x; ++x) {
			if (board.arr[y][x].is_way && board.arr[y][x].how_far_point_is == dist) {
				path[path_len] = 'X';
			} else if (board.arr[y][x].is_way) {
				path[path_len] = '*';
			} else if (board.arr[y][x].how_far_point_is == dist) {
				path[path_len] = 'D';
			} else if (board.arr[y][x].is_obstacle) {
				path[path_len] = '#';
			} else {
				path[path_len] = '.';
			}
			path_len++;
		}
		path[path_len] = '\n';
		path_len++;
	}
	return path;
}

int main(int argc, char **argv) {
	char *map_str = mx_file_to_str(argv[1]);

	mx_try_print_usage_error(argc);
    mx_try_print_file_error(argv);
    mx_try_print_str_error(map_str);
	
	t_board board = mx_mapstr_to_board(map_str);
	t_vector2 start = {mx_atoi(argv[2]), mx_atoi(argv[3])};
	t_vector2 finish = {mx_atoi(argv[4]), mx_atoi(argv[5])};

	mx_try_print_coordinates_error(start, &board, map_str);
	mx_try_print_coordinates_error(finish, &board, map_str);
	
	mx_try_print_entry_obstacle_error(&board, map_str, start);
	mx_try_print_exit_obstacle_error(&board, map_str, finish);

	mx_spread_wave(board, start);

	mx_way_home(board, finish);

	mx_try_print_route_not_found_error(&board, map_str, finish);

	int dist = mx_get_max(board);

	mx_printstr("dist=");
	mx_printint(dist);
	mx_printstr("\n");
	mx_printstr("exit=");
	mx_printint(board.arr[finish.y][finish.x].how_far_point_is);
	mx_printstr("\n");

	char *path = mx_get_path_str(board, map_str, dist);
	mx_write_to_file("path.txt", path);

	mx_free_board(&board);
	free(map_str);
	free(path);

	return 0;
}

