NAME = so_long
DEPS = lib/Libft/libft.a lib/MLX42/build/libmlx42.a
CC = gcc
SRCS_DIR = src/
GNL_SRC_DIR = lib/GNL/
CFLAGS = -Wall -Werror -Wextra -Iincludes -g3 -Ilib/Libft/includes -Ilib/MLX42/include
LIB_FLAGS = -Llib/Libft -lft -Llib/MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
ARFLAGS = -rcs
RM = rm -f
GNL_SRCS = get_next_line.c
SRCS = so_long.c init.c read_file.c throw_error.c close_file.c free_map.c clean.c open_file.c print_map.c check_map_wrong.c
GNL_DIR_PREFIX = $(addprefix $(GNL_SRC_DIR), $(GNL_SRCS))
DIR_PREFIX = $(addprefix $(SRCS_DIR), $(SRCS))
GNL_OBJS = $(GNL_DIR_PREFIX:.c=.o)
OBJS = $(DIR_PREFIX:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(DEPS) $(OBJS) $(GNL_OBJS)
	$(CC) $(OBJS) $(GNL_OBJS) $(LIB_FLAGS) -o $(NAME)

$(DEPS):
	make -C lib/Libft
	make -C lib/MLX42

clean :
	$(RM) $(OBJS) $(GNL_OBJS)
	make -C lib/Libft fclean
	# make -C lib/MLX42 fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all
