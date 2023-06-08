NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

INCLUDE = -I ./include
SRC_DIR = ./src
SRC = ft_printf.c \
		ft_printf_char.c \
		ft_printf_string.c \
		ft_printf_int.c \
		ft_printf_hex.c \
		ft_printf_pointer.c \
		ft_printf_utils.c \
		ft_printf_utils_int.c \
		ft_printf_utils_hex.c 
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus