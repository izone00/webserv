# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjilee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:25:35 by eunjilee          #+#    #+#              #
#    Updated: 2023/02/16 15:44:41 by eunjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CXX = c++
#CXXFLAGS = -Wall -Wextra -Werror

HTTP = 	HttpMessage.cpp \
		HttpRequestMessage.cpp \
		HttpResponseMessage.cpp \
		HttpResponseBuilder.cpp \
		Utils.cpp \
		main.cpp \
		
SRCS = $(addprefix srcs/, $(HTTP))
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

.c.o :
		$(CXX) $(CXXFLAGS) -c -o $(<:.cpp=.o) $<

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re .c.o
