#include "../inc/header.h"

bool mx_empty_pos_is_correct(t_board board, t_vector2 pos) {
	if (pos.x >= 0 && pos.x < board.size.x)
		if (pos.y >= 0 && pos.y < board.size.y)
			if (!board.arr[pos.y][pos.x].is_obstacle)
				if (board.arr[pos.y][pos.x].how_far_point_is == -1)
					return true;
	return false;
}

void mx_spread_wave(t_board board, t_vector2 start) {
	board.arr[start.y][start.x].how_far_point_is = 0;
	t_list *list = mx_create_node(start);
	while (list != NULL) {
		t_vector2 position = list->coordinates;
		t_vector2 all_directions[] = {{position.x, position.y - 1},
									  {position.x + 1, position.y},
									  {position.x, position.y + 1},
									  {position.x - 1, position.y}};
		for (int i = 0; i < 4; ++i) {
			if (mx_empty_pos_is_correct(board, all_directions[i])) {
				board.arr[all_directions[i].y][all_directions[i].x].how_far_point_is
				= board.arr[position.y][position.x].how_far_point_is + 1;
				mx_push_back(&list, all_directions[i]);
			}
		}
		mx_pop_front(&list);
	}
}

