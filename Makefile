# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:51:59 by ayassin           #+#    #+#              #
#    Updated: 2023/07/03 09:27:05 by ayassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SUBDIRS = ex00 ex01 ex02

all:
	@for dir in $(SUBDIRS); do \
        $(MAKE) all -C $$dir; \
    done

clean:
	@for dir in $(SUBDIRS); do \
        $(MAKE) clean -C $$dir; \
    done

fclean: clean
	@for dir in $(SUBDIRS); do \
        $(MAKE) fclean -C $$dir; \
    done

re : fclean all

.PHONY: clean fclean all re