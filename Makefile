# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarin-p <fmarin-p@student-42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 19:28:34 by fmarin-p          #+#    #+#              #
#    Updated: 2022/07/26 18:01:43 by fmarin-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -g -Wall -Wextra -Werror -I$(INCDIR)

SRCFILES = main.c stack_op.c stack_op_2.c parsing.c algorithm.c algorithm_op.c \
		algorithm_op_2.c algorithm_big.c 
OBJFILES = $(SRCFILES:.c=.o)

SRCOBJ = $(addprefix $(OBJDIR), $(OBJFILES))

SRCDIR = src/
INCDIR = include/
OBJDIR = obj/

all: $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) bonus -C libft
	gcc -o $@ $^ libft/libft.a
	cp $@ push_swap_tester/

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p obj
	gcc -c $(CFLAGS) $^ -o $@

clean:
	$(MAKE) fclean -C libft
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
