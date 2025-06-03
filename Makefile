NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/$(SRC_DIR)

SRCS = main.c \
$(SRC_DIR)/read_map.c \
$(SRC_DIR)/utils.c \
$(SRC_DIR)/validate_map.c \
$(SRC_DIR)/validate_path.c \
$(SRC_DIR)/get_next_line.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIRS):
	@mkdir -p $@

$(NAME): $(OBJ_DIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re