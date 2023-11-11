NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SOURCES = 	ft_printf.c			\
			ft_puti.c			\
			ft_putpercente.c	\
			ft_puts.c			\
			ft_putx.c			\
			ft_putX.c			\
			ft_putc.c			\
			ft_putp.c

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