CC = gcc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs
REMOVE = rm -f

SOURCE_FILES = fprintf.c
HEADER_FILES = fprintf.h
OBJ_FILES = $(SOURCE_FILES:.c=.o)
BONUS_SOURCE_FILES = fprintf_bonus.c
BONUS_HEADER_FILES = fprintf_bonus.h
BONUS_OBJ_FILES = $(BONUS_SOURCE_FILES:.c=.o)
LIBFT_DIR = ./libft

NAME = libftprintf.a
BONUS_NAME = $(NAME:.a=_bonus.a)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILES) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a ./$(NAME)
	AR $(NAME) $(OBJ_FILES)

bonus: $(BONUS_NAME)

$(LIBFT_DIR)/libft.a:
	make -C libft $(LIBFT_DIR)

$(BONUS_NAME): $(OBJ_FILES) $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a ./$(BONUS_NAME)
	AR $(BONUS_NAME) $(OBJ_FILES)
	cp $(BONUS_NAME) $(NAME)

%_bonus.o: %_bonus.c $(BONUS_HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	REMOVE $(OBJ_FILES) $(BONUS_OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	REMOVE $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SOURCE_FILES) $(HEADER_FILES) $(BONUS_SOURCE_FILES) $(BONUS_HEADER_FILES)

.PHONY: all bonus clean fclean norm re
