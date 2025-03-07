NAME := so_long
BONUS_PART := so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra

libft = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_puts.c libft/ft_putstr_fd.c libft/ft_reverse.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c 

libft_obj = $(libft:.c=.o)

gnl = gnl/get_next_line.c gnl/get_next_line_utils.c 

gnl_obj = $(gnl:.c=.o)

parser = parser/parser.c parser/errors.c parser/map_checker.c parser/errors_map_checker.c parser/parser_util.c parser/map_checker_util.c

parser_obj= $(parser:.c=.o)

game_bonus = create_game_bonus.c game_util_bonus.c create_animation.c enemy.c so_long_bonus.c
game_bonus_obj = $(game_bonus:.c=.o)

game = create_game.c game_util.c so_long.c
game_obj = $(game:.c=.o)


all: $(NAME)

$(NAME): $(parser_obj) $(game_obj) $(gnl_obj) $(libft_obj)
	$(CC) $(CFLAGS) $(game_obj) $(parser_obj) $(gnl_obj) $(libft_obj) -lmlx -lX11 -lm -lXext -o $(NAME)

bonus: $(BONUS_PART)

$(BONUS_PART): $(parser_obj) $(game_bonus_obj) $(gnl_obj) $(libft_obj)
	$(CC) $(CFLAGS) $(game_bonus_obj) $(parser_obj) $(gnl_obj) $(libft_obj) -lmlx -lX11 -lm -lXext -o $(BONUS_PART)

clean:
	rm -rf $(parser_obj) $(game_obj) $(gnl_obj) $(libft_obj) $(game_bonus_obj)

fclean:
	rm -rf $(NAME) $(BONUS_PART)

re: clean all
