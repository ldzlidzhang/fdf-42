# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 11:27:33 by lidzhang          #+#    #+#              #
#    Updated: 2022/12/07 14:11:46 by lidzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf.a

CC			=	cc
WFLAGS		=	-Wall -Wextra -Werror
MAFLAGS		=	-lm
MIFLAGS		=	-l mlx -l ft -framework OpenGL -framework Appkit
FTLIB		=	./libft/ft_libft.a
SRCS_DIR	=	./srcs
INCLUDE		=	./include/fdf.h

SRCS		=
OBJS		=	$(SRCS:.c=.o)

all : 			$(NAME)

$(NAME):		$(OBJS) $(INCLUDE)
				cp $(FTLIB) ./$(NAME)
				ar rsc $(NAME) $(OBJS)
c.o. :
				$(CC) $(WFLAGS) $(MAFLAGS) $(MIFLAGS) $(INCLUDE) $(SRCS) -o $(OBJS)

libft :
				@$(MAKE) -C ./libft

clean :
				@$(MAKE) -C ./libft clean
				@rm -rf $(OBJS)

fclean : 		clean
				@$(MAKE) -C ./libft fclean
				@rm -rf $(NAME)

re : 			fclean all

.PHONY: all clean fclean re libft
