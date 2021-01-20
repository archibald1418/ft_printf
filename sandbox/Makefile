NAME		= ./libftprintf.a
LIB			= ./libft/libft.a
INCLUDES	= ./includes
TESTFILE	= ft_printf_main.c
SRCS		= ./srcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJS		= ${SRCS:.c=.o}

### UDOLI
TESTFLAGS	= -g -Wall

.c.o:
	${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	ar rcs $(NAME) $?

$(LIB):
	make -C ./libft
	cp $(LIB) $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean:
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

###  TESTS ### TODO: UDOLI!!!111

test:
	$(CC) $(TESTFLAGS) -L. -lftprintf $(TESTFILE)

.PHONY: all clean fclean re
	










