SOURCE = ft_printf_utils.c ft_parse_flag.c ft_printf.c ft_printchar.c ft_printstr.c ft_printhex.c ft_printnbr.c ft_printunbr.c ft_printptr.c

OBJ = ${SOURCE:.c=.o}

NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:	all

$(NAME):	$(LIBFT) $(OBJ)
			cp	$(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJ)

$(LIBFT):
			make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJ}

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus libft
