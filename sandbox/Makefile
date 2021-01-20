NAME		= ./libftprintf.a
LIB			= ./libft/libft.a
INCLUDES	= ./includes
SRCS		= ./srcs/*		### TODO: write all c's by hand
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJS		= ${SRCS:.c=.o}
TESTFILE	= ft_printf_main.c

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

test: all
	$(CC) $(TESTFLAGS) -I $(INCLUDES) -L. -lftprintf $(TESTFILE)

testclean: test
	rm a.out
	rm -rf *.dSYM


.PHONY: all clean fclean re
	










