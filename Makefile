# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 16:09:42 by mcarc             #+#    #+#              #
#    Updated: 2019/11/25 15:59:18 by mcarc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INCLUDE = ./srcs/
SRC += $(INCLUDE)fillit.c
SRC += $(INCLUDE)fillit_errors.c
SRC += $(INCLUDE)fillit_helper.c
SRC += $(INCLUDE)fillit_list.c
SRC += $(INCLUDE)fillit_parse.c
SRC += $(INCLUDE)fillit_validate.c
SRC += $(INCLUDE)fillit_print.c
SRC += $(INCLUDE)ft_fillit_alg.c
SRC += $(INCLUDE)ft_fillit_first.c

SRCDEL = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCDEL)
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@/bin/rm -f $(SRCDEL)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
