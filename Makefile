# project
NAME = libft.a

# compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar -rcs

# sources
SRC = 	src_gnl/ft_get_next_line.c \
		src_str/ft_str_utils1.c \
	 	src_str/ft_str_utils2.c \
		src_str/ft_split.c \
		src_memory/ft_memory.c \
		src_print/ft_print_fd.c \
		src_print/ft_putstr_fd.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) -o $@ -c $^

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SILENT: all clean fclean re
