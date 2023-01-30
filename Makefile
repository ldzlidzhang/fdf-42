# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 11:27:33 by lidzhang          #+#    #+#              #
#    Updated: 2023/01/30 20:34:44 by lidanzhang       ###   ########.fr        #
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

INCLUDE		=	./srcs/fdf.h

SRCS		=	./srcs/main.c \
				./srcs/menu.c \
				./srcs/plot_line.c \
				./srcs/prg_ctrl_1.c \
				./srcs/prg_ctrl_2.c \
				./srcs/read_value.c \
				./srcs/render_map.c \
				./srcs/utility1.c \
				./srcs/utility2.c \
				./srcs/warning_message.c 
				
OBJS		=	$(SRCS:.c=.o)

all : 			$(NAME)

$(NAME):		$(OBJS)
				make -C $(SOURCE)
				make -C $(LIBFT_PATH)
				$(CC) $(WFLAG) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean :
				make clean -C $(SOURCE)
				make clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)

fclean : 		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re : 			fclean all

.PHONY: all clean fclean re
