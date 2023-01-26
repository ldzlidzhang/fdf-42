# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 11:27:33 by lidzhang          #+#    #+#              #
#    Updated: 2023/01/26 11:08:53 by lidzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

CC			=	cc
WFLAGS		=	-Wall -Wextra -Werror
OPENGL		=	-lmlx -framework OpenGL -framework AppKit

RM			=	/bin/rm -f

MLXLINK		=	-L resource/minilibx_macos
MINILIBX	=	-I resource/minilibx_macos
SOURCE		=	./resource/minilibx_macos/

LIBFT		=	./libft/libft.a
LIBFT_PATH	=	./libft

INCLUDE		=	./fdf.h

SRCS		=
OBJS		=	$(SRCS:.c=.o)

all : 			$(NAME)

$(NAME):		$(OBJS)
				make -C $(SOURCE)
				make -C $(LIBFT_PATH)
				$(CC) $(WFLAG) $(MLXLINK) $(MINILIBX) $(INCLUDE) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean :
				make clean -C $(SOURCE)
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)

fclean : 		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re : 			fclean all

.PHONY: all clean fclean re
