NAME = libftprintf.a

#name of the executable

sources = ft_printf.c func_aux.c ft_putwords.c

sources_o = ft_printf.o func_aux.o ft_putwords.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

#allowed flags

all: $(NAME)

#default compiler

$(NAME): $(sources_o)
	ar -crs $(NAME) $(sources_o)

functions_o: $(sources) 
	$(CC) -c -o $(sources)

clean: ;
	rm -f $(sources_o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
