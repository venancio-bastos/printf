NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC= $(shell find . -name "*.c")

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re