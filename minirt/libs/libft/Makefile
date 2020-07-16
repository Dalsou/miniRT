# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 15:11:50 by afoulqui          #+#    #+#              #
#    Updated: 2020/07/16 14:10:03 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME	=	libft.a

HEADER	=	./includes/libft.h ./includes/get_next_line.h ./includes/ft_printf.h

OBJ_DIR =	objs/
INC_DIR = 	$(shell find includes -type d)
SRC_DIR = 	$(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC		= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
IFLAG = 	$(foreach dir, $(INC_DIR), -I $(dir))

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

all:		$(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation ... $(foreach file, $< , $(notdir $<))"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<
			
$(NAME):	$(OBJ) $(INC_DIR) Makefile
			@echo "\n\t\033[36;1m*.............................*"
			@echo "\n\t*     Compilation $(NAME)     *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
			@echo "\n\t\033[036;1m*.............................*\033[0m"
			@ar rcs ${NAME} ${OBJ}

debug :		$(OBJ) $(INC_DIR) Makefile
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) main.c 

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

# ----------------- #
#       CLEAN       #
# ----------------- #

RM		=	rm -rf

clean:	
			$(RM) objs

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
