NAME = libft.a

FT_CAST_DIR = src/ft_cast/
FT_CAST_FIL =	\
	ft_atoi		\
	ft_itoa
FT_CAST_SRC =	\
	$(addsuffix .c, $(addprefix $(FT_CAST_DIR), $(FT_CAST_FIL)))

FT_CHAR_DIR = src/ft_char/
FT_CHAR_FIL = 	\
	ft_isalnum	\
	ft_isalpha	\
	ft_isascii	\
	ft_isdigit	\
	ft_isprint	\
	ft_tolower	\
	ft_toupper
FT_CHAR_SRC =	\
	$(addsuffix .c, $(addprefix $(FT_CHAR_DIR), $(FT_CHAR_FIL)))

FT_LIST_DIR = src/ft_list/
FT_LIST_FIL =			\
	ft_lstadd_back		\
	ft_lstadd_front		\
	ft_lstclear			\
	ft_lstdelone		\
	ft_lstiter			\
	ft_lstlast			\
	ft_lstmap			\
	ft_lstnew			\
	ft_lstsize			\
	ft_lstwritecontent
FT_LIST_SRC =	\
	$(addsuffix .c, $(addprefix $(FT_LIST_DIR), $(FT_LIST_FIL)))

FT_MEMORY_DIR = src/ft_memory/
FT_MEMORY_FIL = \
	ft_bzero	\
	ft_calloc	\
	ft_memchr	\
	ft_memcmp	\
	ft_memcpy	\
	ft_memmove	\
	ft_memset
FT_MEMORY_SRC =	\
	$(addsuffix .c, $(addprefix $(FT_MEMORY_DIR), $(FT_MEMORY_FIL)))

FT_PUT_DIR = src/ft_put/
FT_PUT_FIL = 		\
	ft_putchar_fd	\
	ft_putendl_fd	\
	ft_putnbr_fd	\
	ft_putstr_fd
FT_PUT_SRC =		\
	$(addsuffix .c, $(addprefix $(FT_PUT_DIR), $(FT_PUT_FIL)))

FT_STRING_DIR = src/ft_string/
FT_STRING_FIL =	\
	ft_split	\
	ft_strchr	\
	ft_strdup	\
	ft_striteri	\
	ft_strjoin	\
	ft_strlcat	\
	ft_strlcpy	\
	ft_strlen	\
	ft_strmapi	\
	ft_strncmp	\
	ft_strnstr	\
	ft_strrchr	\
	ft_strtrim	\
	ft_substr
FT_STRING_SRC =	\
	$(addsuffix .c, $(addprefix $(FT_STRING_DIR), $(FT_STRING_FIL)))

SRCS =					\
	$(FT_CAST_SRC)		\
	$(FT_CHAR_SRC)		\
	$(FT_LIST_SRC)		\
	$(FT_MEMORY_SRC)	\
	$(FT_PUT_SRC)		\
	$(FT_STRING_SRC)

OBJS = $(SRCS:.c=.o)

CC 			= @cc
RM 			= @rm -rf
CFLAGS 		= -Wall -Wextra -Werror

OBJ_COLOR	= "\e[38;5;147m"
CLN_COLOR	= "\e[38:5:124m"
BIN_COLOR	= "\e[38;5;129m"
ERASE_LINE = "\e[2K\r"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf $(ERASE_LINE)$(BIN_COLOR)"\t"$(NAME)"\t\t\t\t[ ✓ ]\n\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(ERASE_LINE)$(OBJ_COLOR)"\t"$@"\e[0m"

clean:
	$(RM) $(OBJS)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" objects\t\t[ ✓ ]\n\e[0m"

fclean: clean
	$(RM) $(NAME)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" binary\t\t[ ✓ ]\n\e[0m"

re: fclean all

.PHONY: all re clean fclean