#include "../inc/header.h"

char *mx_strnew(const int size) {
	if (size <= -1) return NULL;
	char *string = malloc((size + 1) * sizeof(char));
	if (string == NULL) return NULL;
	for (int i = 0; i < size + 1; ++i)
		string[i] = '\0';
	return string;
}

