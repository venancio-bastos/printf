NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = 

OBJ =

RM = rm -rf

all: $(NAME)

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	rm -f

.PHONY: all clean fclean re