CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx

USR_INCLUDE = -I/usr/include
USRLIB_FLAGS = -L/usr/lib -lXext -lX11 -lm

SRCS_DIR = ./srcs/
SRCS_FILES = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#INCLUDES = -I./includes



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(MLX_INCLUDE) $(USRLIB_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(USR_INCLUDE) $(MLX_INCLUDE) -O3 -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
