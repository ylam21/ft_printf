NAME = libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = ./src
SRC_DIR_CONV = $(SRC_DIR)/conversion
OBJ_DIR = ./objects
OBJ_DIR_CONV = $(OBJ_DIR)/conversion
LIBFT_DIR = ./libft

# File names
SRC_FILES = ft_printf.c
SRC_FILES_CONV = ft_write_c.c ft_write_s.c ft_write_p.c ft_write_d.c ft_write_i.c ft_write_u.c ft_write_x.c ft_write_upx.c

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

# Test
TEST_DIR = ./tests
TEST_FILES =  test_write_c.c test_write_s.c test_write_p.c test_write_d.c test_write_i.c test_write_u.c test_write_x.c test_write_upx.c
TEST_SRC = $(addprefix $(TEST_DIR)/, $(TEST_FILES))
TEST_BIN_DIR = ./tests_bin
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%.out, $(TEST_SRC))

tests: $(TEST_BIN_DIR) $(TEST_BINS)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

$(TEST_BIN_DIR)/%.out: $(TEST_DIR)/%.c libftprintf.a libft/libft.a
	$(CC) $(CFLAGS) -Ilibft -I. -o $@ $< libftprintf.a libft/libft.a

run_tests: tests
	@for bin in $(TEST_BINS); do \
		echo "[Running $$bin...]"; \
		./$$bin || exit 1; \
	done

clean_tests:
	rm -rf $(TEST_BIN_DIR)

re: fclean all

.PHONY: all clean fclean re tests run_tests clean_tests
