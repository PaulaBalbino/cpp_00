# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:35:45 by pbalbino          #+#    #+#              #
#    Updated: 2024/03/07 15:18:26 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJPATH = ./obj/

SRC = phonebook.cpp

OBJ = $(addprefix $(OBJPATH), $(SRC:.cpp=.o))

all:	$(OBJPATH) $(NAME)

$(OBJPATH):
	mkdir $(OBJPATH)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJPATH)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJPATH)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
