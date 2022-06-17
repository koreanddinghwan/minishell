# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:11:43 by myukang           #+#    #+#              #
#    Updated: 2022/06/17 23:46:12 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
\CFLAGS = -fsanitize=address -g3
INC = ./includes

RDINC = ${HOME}/.brew/opt/readline/include #readline include path
RDLIB = ${HOME}/.brew/opt/readline/lib #readline lib path
RDFLAGS = -I${RDINC} -L${RDLIB} -lreadline #readline compile flags

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

MAIN_SRCS = $(addprefix ./srcs/main_srcs/, main.c sig_handler.c display.c initialize_main.c initialize_data.c )
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

TOKEN_SRCS = $(addprefix ./srcs/token_srcs/, tokenizer.c lexer.c token_buf_build.c  lexer_token_init.c lexer_decide_w_type.c lexer_word_converter.c)
TOKEN_OBJS = $(TOKEN_SRCS:.c=.o)

PARSE_SRCS = $(addprefix ./srcs/parsing_srcs_m/, parser.c parser_tools.c  \
			 simple_cmd.c pipe_cmd.c make_input_lst.c make_output_lst.c \
			 make_heredoc_lst.c make_append_lst.c make_cmd.c make_args.c)
PARSE_OBJS = $(PARSE_SRCS:.c=.o)

EXEC_SRCS = $(addprefix ./srcs/execute_srcs/, execute.c)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

BUILTIN_SRCS = $(addprefix ./srcs/builtin_srcs/, ft_cd.c ft_pwd.c ft_exit.c ft_export.c ft_unset.c ft_echo.c)
BUILTIN_OBJS = $(BUILTIN_SRCS:.c=.o)

OBJ_FILES = $(MAIN_OBJS) $(BUILTIN_OBJS) $(TOKEN_OBJS) $(PARSE_OBJS) $(EXEC_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -j 4 -C $(FTDIR) #recursively create libft
	cp $(FTDIR)$(FT) ./$(FT) #copy in root dir
	$(GCC) $(CFLAGS) $(RDFLAGS) -I$(INC) -I$(FTINC) -o $@ $^ libft.a #RFLAGS for readline lib

%.o : %.c
	$(GCC) $(CFLAGS) -I$(RDINC) -I$(INC) -I$(FTINC) -c $^ -o $@ #specify readline header in RNINC

fclean : clean
	rm -rf $(NAME)

clean :
	make fclean -C $(FTDIR)
	rm -rf $(OBJ_FILES) $(FT)

re : 
	make fclean;
	make all;

.PHONY : all fclean clean re
