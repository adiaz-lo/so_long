NAME = so_long

DEPS = Libft/libft.a Libft/src/GNL/get_next_line.c lib/MLX42/build/libmlx42.a

CC = gcc

SRCS_DIR = src/

CCFLAGS = -Wall -Werror -Wextra -g3 -ldl -lglfw -pthread -lm

INCLUDE = includes/so_long.h includes/map.h includes/common.h includes/map.h

ARFLAGS = -rcs

RM = rm -f

SRCS = so_long.c

DIR_PREFIX = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(DIR_PREFIX:.c=.o)

all:	$(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(DEPS):
	make -C Libft

$(NAME): $(DEPS) $(INCLUDE) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(DEPS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	make -C Libft fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all
