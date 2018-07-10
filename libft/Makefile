# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibotha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 17:06:15 by ibotha            #+#    #+#              #
#    Updated: 2018/07/04 18:07:17 by ibotha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HED = libft.h
TEST = ../test/test.c ../test/testmem.c ../test/teststr1.c ../test/itertest.c ../test/testitoa.c ../test/testlist.c
OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memalloc.o ft_memccpy.o ft_memcpy.o ft_memdel.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_memrcpy.o ft_itoa.o ft_itoa_b.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o get_next_line.o ft_putnbr_b.o ft_putnbr_b_fd.o ft_atod.o ft_atoi_b.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "[ \x1b[32mLinking... \x1b[0m]"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[ \x1b[34mLinked libft! \x1b[0m]\n"

$(OBJ): %.o: %.c $(HED)
	@echo "[ \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c -o $@ -Wall -Werror -Wextra

norm:
	@norminette ft_bzero.c
	@norminette *mem*
	@norminette *str*
	@norminette *to*
	@norminette *is*
	@norminette *put*
	@norminette *lst*
	@norminette libft.h

testlibft: all
	@gcc -o ../test/test.exe $(NAME) $(TEST)
	@./../test/test.exe
	@rm -f ../test/test.exe

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all norm testlibft fclean clean re
