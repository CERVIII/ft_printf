# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 16:56:15 by pcervill          #+#    #+#              #
#    Updated: 2022/05/03 13:38:20 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

####FILES####

SRC		= 	ft_printf.c ft_printf_utils.c

OBJ 	= 	$(SRC:%.c=%.o)

####COMPILE####

CFLAGS 	= 	-Wall -Wextra -Werror 

CC		=	gcc

RM 		= 	rm -f

#####COMPILE TARGET####

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
####TARGETS####

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME) 
	$(RM) $(OBJ)

re: fclean all

.PHONY: fclean all clean re
