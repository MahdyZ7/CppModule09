# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 18:00:42 by ayassin           #+#    #+#              #
#    Updated: 2023/07/03 08:33:58 by ayassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = BitcoinExchange.cpp main.cpp

HEADERS = BitcoinExchange.hpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re