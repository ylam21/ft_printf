NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
OBJ_DIR = ./objects
LIBFT_DIR = ./libft
LIBFT_OBJ_DIR = $(OBJ_DIR)/libft

# File lists
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(patsubst $(LIBFT_DIR)/%.c, $(LIBFT_OBJ_DIR)/%.o, $(LIBFT_SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
