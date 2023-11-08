NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SOURCES = ft_printf.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean