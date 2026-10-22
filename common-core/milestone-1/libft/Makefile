NAME = libft.a
SRCS = ft_strlen.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
