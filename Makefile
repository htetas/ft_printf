SOURCE = ft_printf_utils.c ft_parse_flag.c ft_printf.c ft_printchar.c ft_printstr.c ft_printhex.c ft_printnbr.c ft_printunbr.c ft_printptr.c

OBJ = ${SOURCE:.c=.o}

NAME = libftprintf.a

LIBFT_PATH = ./libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

AR = ar Trcs

LIB = ranlib

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:	all

${NAME}:	${OBJ}
		make -C $(LIBFT_PATH) all
		cp $(LIBFT_PATH)/libft.a ./
		cp $(LIBFT_PATH)/libft.h ./
		${AR} ${NAME} ${OBJ} libft.a
		${LIB} ${NAME}

clean:
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJ}

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f ${NAME} libft.a libft.h

re:	fclean all

.PHONY: all clean fclean re bonus
