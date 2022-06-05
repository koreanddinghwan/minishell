NAME = echo
SRCS = ft_echo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(NAME)
