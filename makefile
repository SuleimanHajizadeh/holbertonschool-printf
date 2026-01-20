CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99
SRC = _printf.c check_prtr.c helpers.c \
      func_d.c func_u.c func_o.c func_x.c func_X.c \
      func_c.c func_s.c func_ptg.c func_b.c func_r.c func_R.c \
      main_test.c
OBJ = $(SRC:.c=.o)
NAME = printf_test

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
