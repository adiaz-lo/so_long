NAME = so_long

DEPS = Libft/libft.a Libft/src/GNL/get_next_line.c lib/MLX42/build/libmlx42.a

CC = gcc

SRCS_DIR = src/

CCFLAGS = -Wall -Werror -Wextra -Iincludes

DEB_FLAGS = -g3

LIB_FLAGS = -ldl -lglfw -pthread -lm

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
	$(CC) $(OBJS) $(DEPS) $(CCFLAGS) $(DEB_FLAGS) $(LIB_FLAGS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	make -C Libft fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all
