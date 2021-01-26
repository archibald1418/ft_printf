NAME		= 	libftprintf.a
DIR			=	srcs/
SRC			=	ft_utils.c\
				ft_printers.c\
				ft_printf.c\
				ft_ultoa_base.c\
				ft_parser.c\
				ft_parser_utils.c\
				ft_setters.c

CC			=	gcc
SOURCE		=	$(addprefix $(DIR), $(SRC))
OBJ			=	${SOURCE:.c=.o}
INCLUDES	=	./includes
FLAGS		=	-Wall -Wextra -Werror
LIB			=	./libft/libft.a
SANITIZE	= -fsanitize=address

### TESTS ###
TESTSRC		= ft_print_data.c
TESTFILE 	= main.c
TESTDIR		= tests/
TESTSOURCE	= $(addprefix $(TESTDIR), $(TESTSRC))

all: $(NAME)
$(NAME): $(OBJ) $(LIB)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o: %.c $(INCLUDES)
	${CC} $(FLAGS) -I $(INCLUDES) -c $< -o $@
$(LIB):
	make -C ./libft
	cp libft/libft.a libftprintf.a
clean:
	rm -f $(OBJ)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all
.PHONY: all clean fclean re

### UDOLI ###
test: $(LIB)
	$(CC) -g -I $(INCLUDES) $(SOURCE) main.c libft/*.c tests/$(TESTSRC)
	./a.out;

test-struct:
	$(CC) -g -I $(INCLUDES) $(TESTDIR)/ft_print_data.c main.c $(SOURCE) $(LIB)
	./a.out

test-master:
	$(CC) -g -I $(INCLUDES) master_main.c $(SOURCE) $(LIB)
	./a.out

test-archive: all
	$(CC) -I $(INCLUDES)  $(SANITIZE) -L. -lftprintf main.c
