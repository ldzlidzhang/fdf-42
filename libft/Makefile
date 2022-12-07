# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 20:47:29 by lidanzhang        #+#    #+#              #
#    Updated: 2022/12/07 14:04:35 by lidzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I./ft_printf.h
LIBFT 		=	./libft/libft.a

RM			=	rm -f

SRCS		=	./ft_printf.c ./ft_print_str.c \
				./ft_print_unsigned.c ./ft_print_pointer.c ./ft_print_hex.c

OBJS		=	$(SRCS:.c=.o)

all : 			$(NAME)

$(NAME) : 		$(OBJS) libft
				cp libft/libft.a ./$(NAME)
				ar rsc $(NAME) $(OBJS) 

c.o. :
				$(CC) $(FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

libft :
				@$(MAKE) -C ./libft all

clean :
				@$(MAKE) -C ./libft clean
				@rm -rf $(OBJS)

fclean : 		clean
				@$(MAKE) -C ./libft fclean
				@rm -rf $(NAME)

re : 			fclean all

.PHONY: all clean fclean re libft