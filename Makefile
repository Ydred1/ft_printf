NAME = libftprintf.a

LIBFT 	= ./lib/libft/

SRC_DIR =	./src/
SRC_FIL =				\
	ft_printf			\
	ft_puti			\
	ft_putpercente	\
	ft_puts			\
	ft_putx			\
	ft_putX			\
	ft_putc			\
	ft_putp			\
	ft_putu
SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FIL)))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = @rm -f

OBJ_COLOR	= "\e[38;5;147m"
CLN_COLOR	= "\e[38:5:124m"
BIN_COLOR	= "\e[38;5;129m"
ERASE_LINE  = "\e[2K\r"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)libft.a
	@cp $(LIBFT)libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf $(ERASE_LINE)$(BIN_COLOR)"\t"$(NAME)"\t\t\t[ ✓ ]\n\e[0m"

$(LIBFT)libft.a:
	@$(MAKE) -C $(LIBFT)

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(ERASE_LINE)$(OBJ_COLOR)"\t"$@"\e[0m"

clean:
	@$(MAKE) fclean -C $(LIBFT)
	$(RM) $(OBJS)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" objects\t[ ✓ ]\n\e[0m"

fclean: clean
	$(RM) $(NAME)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" binary\t[ ✓ ]\n\e[0m"

re: fclean all

.PHONY: all re clean fclean