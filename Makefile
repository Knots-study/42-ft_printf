NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC_DIR = src/
SRC = ft_printf.c \
		ft_printf_char.c \
		ft_printf_string.c \
		ft_printf_int10.c \
		ft_printf_pointer.c \
		ft_printf_hex.c \
		ft_printf_utils.c 
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o)) # オブジェクトファイルを obj/ ディレクトリに生成するように修正

INC_DIR = include/
INC = ft_printf.h
INCS = $(addprefix $(INC_DIR), $(INC))

# ターゲットと依存関係を設定
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJ_DIR) # オブジェクトファイルの依存関係を修正
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR): # オブジェクトファイルを生成するディレクトリを作成するルールを追加
	mkdir -p $(OBJ_DIR)

# クリーンアップルールを修正
clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# ターゲットを all に修正
all: $(NAME)