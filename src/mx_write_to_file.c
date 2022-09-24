#include "../inc/header.h"

void mx_write_to_file(char *file_name, char *str) {
	int file = open(file_name, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	write(file, str, mx_strlen(str));
	close(file);
}

