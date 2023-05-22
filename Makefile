NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
INCLUDES = .
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS): $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDES)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re