NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
BONUS_SRCS = ft_printf_bonus.c
INCLUDES = ft_printf.h
INCLUDES_BONUS = ft_printf_bonus.h
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(OBJS): $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $(SRCS) -I .
$(BONUS_OBJS): $(BONUS_SRCS) $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) -c $(BONUS_SRCS) -I .

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re