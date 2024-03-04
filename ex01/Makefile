# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:35:45 by pbalbino          #+#    #+#              #
#    Updated: 2024/03/04 10:36:21 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

OBJPATH = ./obj/

SRC = phonebook.cpp

OBJ = $(addprefix $(OBJPATH), $(SRC:.cpp=.o))

all:	$(OBJPATH) $(NAME)

$(OBJPATH):
	mkdir $(OBJPATH)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(OBJPATH)%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

clean: rm -rf $(OBJPATH)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
