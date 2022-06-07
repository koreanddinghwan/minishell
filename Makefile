# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:11:43 by myukang           #+#    #+#              #
#    Updated: 2022/06/07 14:06:06 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ./includes

RDINC = ${HOME}/.brew/opt/readline/include #readline include path
RDLIB = ${HOME}/.brew/opt/readline/lib #readline lib path
RDFLAGS = -I${RDINC} -L${RDLIB} -lreadline #readline compile flags

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

MAIN_SRCS = $(addprefix ./srcs/main_srcs/, main.c sig_handler.c display.c set_envkey.c initialize_main.c)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

BUILTIN_SRCS = $(addprefix ./srcs/builtin_srcs/, )
BUILTIN_OBJS = $(BUILTIN_SRCS:.c=.o)

TOOLS_SRCS = $(addprefix ./srcs/tools/, error_handler.c)
TOOLS_OBJS = $(TOOLS_SRCS:.c=.o)

OBJ_FILES = $(MAIN_OBJS) $(BUILTIN_OBJS) $(TOOLS_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(FTDIR) #recursively create libft
	cp $(FTDIR)$(FT) ./$(FT) #copy in root dir
	make fclean -C $(FTDIR) #fclean libft.a and .o files in ./libft
	$(GCC) $(CFLAGS) $(RDFLAGS) -I$(INC) -I$(FTINC) -o $@ $^ libft.a #RFLAGS for readline lib

%.o : %.c
	$(GCC) $(CFLAGS) -I$(RDINC) -I$(INC) -I$(FTINC) -c $^ -o $@ #specify readline header in RNINC

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ_FILES) $(FT)

re : 
	make fclean;
	make all;

.PHONY : all fclean clean re
