NAME		= 	libftprintf.a
DIR			=	srcs/
SRC			=	ft_utils.c\
				ft_printers.c\
				ft_printf.c\
				ft_ultoa_base.c\
				ft_parser.c
CC			=	gcc
SOURCE		=	$(addprefix $(DIR), $(SRC))
OBJ			=	${SOURCE.c:=.o}
INCLUDES	=	./includes
FLAGS		=	-Wall ### ADD -Wall -Werror -Wextra later
LIB			=	libft/libft.a

### UDOLI ###
TESTFILE 	= ft_printf_main.c
TESTSRCS	= ./tests/*.c

all: $(NAME)
$(NAME): $(OBJ) $(LIB)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o: %.c
	${CC} $(FLAGS) -I $(INCLUDES) -c $< -o $@
$(LIB):
	make -C libft
	cp $(LIB) $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all
.PHONY: all clean fclean re bonus

### UDOLI ###
test: $(LIB)
	$(CC) -g -I $(INCLUDES) $(SOURCE) $(TESTSRCS) $(TESTFILE) libft/*.c
