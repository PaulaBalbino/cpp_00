# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 15:20:24 by pbalbino          #+#    #+#              #
#    Updated: 2024/03/07 15:18:13 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJPATH = ./obj/

SRC = megaphone.cpp

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
