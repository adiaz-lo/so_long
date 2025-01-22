# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:42:32 by adiaz-lo          #+#    #+#              #
#    Updated: 2023/04/24 15:44:17 by adiaz-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

SRC_DIR = src/

GNL_SRC_DIR = src/GNL/

CCFLAGS = -Wall -Werror -Wextra

INCLUDE = includes/libft.h

LIB = ar -rcs

RM = rm -f

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

DIR_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(DIR_PREFIX:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GNL_OBJS = $(GNL_DIR_PREFIX:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME) : $(OBJS) $(INCLUDE) $(GNL_OBJS)
	$(LIB) $(NAME) $(OBJS) $(GNL_OBJS)

bonus : $(OBJS_BONUS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJS_BONUS)

gnl :	$(OBJS) $(GNL_OBJS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJS) $(GNL_OBJS)

clean :
	$(RM) $(OBJS)

gnl_clean : clean
	$(RM) $(GNL_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME) all
