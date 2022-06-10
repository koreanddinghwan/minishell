NAME = a.out
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(HOME)/.brew/opt/readline/include $(HOME)/.brew/opt/readline/lib $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(NAME)
