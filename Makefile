NAME = way_home

all: $(NAME) clean

$(NAME) inc/*.h src/*.c:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic src/*.c -o $(NAME)

uninstall: clean
	rm -rf $(NAME)

clean:

reinstall: uninstall all

