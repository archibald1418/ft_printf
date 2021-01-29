NAME		= 	libftprintf.a
DIR			=	srcs/
SRC			=	ft_utils.c\
				ft_printers.c\
				ft_printers_utils.c\
				ft_printf.c\
				ft_ultoa_base.c\
				ft_parser.c\
				ft_parser_utils.c\
				ft_setters.c
INCLUDES	=	./includes
DIRH		= 	includes/
HFILES		=	ft_printf.h\
				libft.h
HEADERS		=	$(addprefix $(DIRH), $(HFILES))
CC			=	gcc
SOURCE		=	$(addprefix $(DIR), $(SRC))
OBJ			=	${SOURCE:.c=.o}
FLAGS		=	-Wall -Wextra -Werror
LIB			=	./libft/libft.a

all: $(NAME)
$(NAME): $(OBJ) $(LIB)
	ar rc $(NAME) $?
	ranlib $(NAME)
$(OBJ): $(HEADERS)
%.o: %.c
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