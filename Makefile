CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx

USR_INCLUDE = -I/usr/include
USRLIB_FLAGS = -L/usr/lib -lXext -lX11 -lm

SRCS_DIR = ./srcs/
SRCS_FILES = main.c fdf.c free.c map_check.c utils.c color.c gradient.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

FDF_INCLUDE = -I./include
FDF_INCLUDE_FILE = ./include/fdf.h

LIBFT_DIR = ./libft/
LIBFT_INCLUDE = -I./libft/include
LIBFT_FLAGS = -Llibft -lft
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(USRLIB_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(FDF_INCLUDE_FILE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(USR_INCLUDE) $(MLX_INCLUDE) $(FDF_INCLUDE) $(LIBFT_INCLUDE) -O3 -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
