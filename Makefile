NAME := so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
libft = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_puts.c libft/ft_putstr_fd.c libft/ft_reverse.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c 

gnl = gnl/get_next_line.c gnl/get_next_line_utils.c 

mlx = minilibx/libmlx.a
parser = parser/parser.c parser/errors.c parser/map_checker.c parser/errors_map_checker.c parser/parser_util.c parser/map_checker_util.c
game = create_game_bonus.c game_util_bonus.c


ALL: $(NAME)

$(NAME): $(mlx) $(parser) $(game) $(gnl) $(libft) $(ARGS)
	$(CC) $(CFLAGS) $(ARGS) $(game) $(mlx) $(parser) $(gnl) $(libft) -lX11 -lm -lXext -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all
