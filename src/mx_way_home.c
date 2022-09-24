#include "../inc/header.h"

void mx_way_home(t_board board, t_vector2 exit) {
	int x = exit.x;
	int y = exit.y;
	int distance = board.arr[y][x].how_far_point_is;

	board.arr[y][x].is_way = true;
	for (int i = distance; i >= 0; ) {
		if (board.arr[y][x].how_far_point_is == 0)
			break;
		if (x + 1 < board.size.x && board.arr[y][x].how_far_point_is == board.arr[y][x + 1].how_far_point_is + 1) {
			board.arr[y][x + 1].is_way = true;
			x++;
			i--;
		}
		else if (x - 1 >= 0 && board.arr[y][x].how_far_point_is == board.arr[y][x - 1].how_far_point_is + 1) {
			board.arr[y][x - 1].is_way = true;
			x--;
			i--;
		}
		else if (y + 1 < board.size.y && board.arr[y][x].how_far_point_is == board.arr[y + 1][x].how_far_point_is + 1) {
			board.arr[y + 1][x].is_way = true;
			y++;
			i--;
		}
		else if (y - 1 >= 0 && board.arr[y][x].how_far_point_is == board.arr[y - 1][x].how_far_point_is + 1) {
			board.arr[y - 1][x].is_way = true;
			y--;
			i--;
		}
		else {
			break;
		}
	}
}

