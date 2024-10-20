LIBFT =	Libft/libft.a

SRCS = main.c

gcc:
	gcc *.c lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

all:	$(LIBFT) $(SRCS)
	gcc *.c Libft/src/GNL/get_next_line.c lib/MLX42/build/libmlx42.a Libft/libft.a -ldl -lglfw -pthread -lm -g3 #-Wall -Werror -Wextra 
