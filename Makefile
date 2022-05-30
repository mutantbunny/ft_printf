CC = cc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs
REMOVE = rm -f

SOURCE_FILES = ft_printf.c gen_parsers.c int_parsers.c utils.c
HEADER_FILES = ft_printf.h
OBJ_FILES = $(SOURCE_FILES:.c=.o)
BONUS_SOURCE_FILES = ft_printf_bonus.c main_parsers_bonus.c \
						gen_parsers_bonus.c int_parsers_bonus.c \
						dec_utils_bonus.c hex_utils_bonus.c utils_bonus.c
BONUS_HEADER_FILES = ft_printf_bonus.h
BONUS_OBJ_FILES = $(BONUS_SOURCE_FILES:.c=.o)
LIBFT_DIR = ./libft

NAME = libftprintf.a
NAME_BONUS = $(NAME:.a=_bonus.a)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILES) $(LIBFT_DIR)/libft.a
	$(REMOVE) $(NAME_BONUS)
	cp $(LIBFT_DIR)/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJ_FILES)

bonus: $(NAME_BONUS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

$(NAME_BONUS): $(BONUS_OBJ_FILES) $(LIBFT_DIR)/libft.a
	$(REMOVE) $(OBJ_FILES)
	$(REMOVE) $(NAME)
	cp $(LIBFT_DIR)/libft.a ./$(NAME_BONUS)
	$(AR) $(NAME_BONUS) $(BONUS_OBJ_FILES)
	cp $(NAME_BONUS) $(NAME)

%_bonus.o: %_bonus.c $(BONUS_HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean:
	$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	$(REMOVE) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SOURCE_FILES) $(HEADER_FILES) $(BONUS_SOURCE_FILES) $(BONUS_HEADER_FILES)

.PHONY: all bonus clean fclean norm re
