# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:11:43 by myukang           #+#    #+#              #
#    Updated: 2022/06/06 01:06:22 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ./includes
RDINC = ${HOME}/.brew/opt/readline/include #readline include path
RDLIB = ${HOME}/.brew/opt/readline/lib
RDFLAGS = -I${RDINC} -L${RDLIB} -lreadline

MAIN_SRCS = $(addprefix ./srcs/main_srcs/, main.c sig_handler.c display.c)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

OBJ_FILES = $(MAIN_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(GCC) $(CFLAGS) $(RDFLAGS) -I$(INC) -o $@ $^

%.o : %.c
	$(GCC) $(CFLAGS) -I$(RDINC) -I$(INC) -c $^ -o $@

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ_FILES)

re : 
	make fclean;
	make all;

.PHONY : all fclean clean re
