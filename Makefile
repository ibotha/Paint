# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibotha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 14:47:39 by ibotha            #+#    #+#              #
#    Updated: 2018/07/10 17:39:59 by ibotha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

DIEDEP = inc/die.h libft/libft.a

DIEOBJ = src/die.o

VISDEP = inc/visuals.h $(DIEOBJ) libft/libft.a

VISOBJ = src/visuals/setup.o src/visuals/draw.o src/visuals/hooks.o src/visuals/mouse.o

OBJDEP = inc/objects.h $(VECOBJ) libft/libft.a $(DIEOBJ)

OBJOBJ = src/objects/sphere.o src/objects/add_objects.o

VECDEP = inc/vector.h libft/libft.a

PARDEP = inc/parse.h $(OBJOBJ) $(VECOBJ)

PAROBJ = src/parser/parser.o

VECOBJ = src/vector/vector.o src/vector/vectorop.o src/vector/vectorio.o

DEP = $(VISOBJ) $(DIEOBJ) $(OBJOBJ) $(PAROBJ) libft/libft.a inc/RTv1.h

OBJ = src/main.o

AOBJ = $(OBJ) $(VISOBJ) $(DIEOBJ) $(OBJOBJ) $(VECOBJ) $(PAROBJ)

FLAGS = -Wall -Werror -Wextra -I inc -I libft

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@echo "[ \x1b[32mLinking $@ \x1b[0m]"
	@gcc $(AOBJ) $(FLAGS) -o $(NAME) libft/libft.a -lmlx -framework OpenGL -framework AppKit && echo "\x1b[35m***$(NAME) Ready***\x1b[0m"

$(OBJ): %.o: %.c $(DEP) 
	@echo "[ \x1b[36mBASE: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

$(DIEOBJ): %.o: %.c $(DIEDEP)
	@echo "[ \x1b[36mDIE: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

$(VISOBJ): %.o: %.c $(VISDEP)
	@echo "[ \x1b[36mVISUALS: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

$(OBJOBJ): %.o: %.c $(OBJDEP)
	@echo "[ \x1b[36mOBJECTS: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

$(VECOBJ): %.o: %.c $(VECDEP)
	@echo "[ \x1b[36mVECTOR: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

$(PAROBJ): %.o: %.c $(PARDEP)
	@echo "[ \x1b[36mVECTOR: \x1b[32mAdding \x1b[33m$@ \x1b[0m]"
	@gcc -c $*.c $(FLAGS) -o $@

libft/libft.a:
	@make -C libft

patience:
	clear
	@echo "\x1b[35mWasting Time: \x1b[32m[#            ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[##           ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[###          ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[####         ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[#####        ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[######       ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[#######      ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[########     ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[#########    ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[##########   ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[###########  ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[############ ]"
	@sleep 1
	clear;
	@echo "\x1b[35mWasting Time: \x1b[32m[#############]"
	@sleep 1
	clear;
	@curl parrot.live

clean:
	@echo "[ \x1b[32mCleaning... \x1b[0m]"
	@make clean -C libft
	@rm -f $(AOBJ)

fclean: clean
	@echo "[ \x1b[32mFull \x1b[0m]"
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re patience
