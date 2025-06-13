NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
SRC_DIR_CONV = $(SRC_DIR)/conversion
OBJ_DIR = ./objects
OBJ_DIR_CONV = $(OBJ_DIR)/conversion
LIBFT_DIR = ./libft

# File names
SRC_FILES = ft_printf.c ft_print_utils.c
SRC_FILES_CONV = ft_write_c.c ft_write_s.c ft_write_p.c

# Sources
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRCS_CONV = $(addprefix $(SRC_DIR_CONV)/, $(SRC_FILES_CONV))

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_CONV = $(patsubst $(SRC_DIR_CONV)/%.c, $(OBJ_DIR_CONV)/%.o, $(SRCS_CONV))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(OBJS_CONV)
	$(MAKE) -C $(LIBFT_DIR)
	ar -rcs $(NAME) $(OBJS) $(OBJS_CONV) $(LIBFT_DIR)/libft.a

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_CONV)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR_CONV)/%.o: $(SRC_DIR_CONV)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_CONV)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

test:
	make re
	cc tests/test.c libftprintf.a
	./a.out

re: fclean all

.PHONY: all clean fclean re test
