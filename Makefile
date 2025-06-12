NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
SRC_DIR_CONV = ./src/conversion
OBJ_DIR = ./objects
OBJ_DIR_CONV = $(OBJ_DIR)/conversion
LIBFT_DIR = ./libft

# Files
SRC_FILES = ft_printf.c ft_print_utils.c
SRC_FILES_CONV = ft_conv_c.c ft_conv_s.c

# Sources
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRCS_CONV = $(addprefix $(SRC_DIR_CONV)/, $(SRC_FILES_CONV))

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_CONV = $(patsubst $(SRC_DIR_CONV)/%.c, $(OBJ_DIR_CONV)/%.o, $(SRCS_CONV))

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_CONV)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(OBJS_CONV)
	$(MAKE) -C $(LIBFT_DIR)
	ar -rcs $(NAME) $(OBJS) $(OBJS_CONV) $(LIBFT_DIR)/libft.a

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
	gcc tests/main.c

re: fclean all

.PHONY: all clean fclean re test
