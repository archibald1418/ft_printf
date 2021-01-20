NAME		= 	libftprintf.a
DIR			=	srcs/
SRC			=	ft_find_specs.c\
				ft_printers.c\
				ft_printf.c\
				ft_ultoa_base.c
CC			=	gcc
SOURCE		=	$(addprefix $(DIR), $(SRC))
OBJ			=	${SOURCE.c:=.o}
INCLUDES	=	./includes
FLAGS		=	-Wall ### ADD -Wall -Werror -Wextra later
LIB			=	libft/libft.a

### UDOLI ###
TEST 	= ft_printf_main.c

all: $(NAME)
$(NAME): $(OBJ) $(LIB)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o: %.c
	${CC} $(FLAGS) -I $(HEADER) -c $< -o $@
$(LIB):
	make -C libft
	cp $(LIB) $(NAME)
clean:
	rm -f $(OBJECT)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all
.PHONY: all clean fclean re bonus

### UDOLI ###
test: $(LIB)
	$(CC) -g -I $(INCLUDES) $(SOURCE) $(TEST) $(LIB)

