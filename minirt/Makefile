# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 11:35:24 by afoulqui          #+#    #+#              #
#    Updated: 2020/07/09 15:03:02 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME		=	minirt

LIB_DIR		=	libs/libft/  libs/minilibx/
LIBFT		=	libs/libft/

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d) libs/libft/includes libs/minilibx

OBJ_DIR		=	objs/

LIB			=	ft mlx
SRC			=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ			=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))
HEADERS		=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))
FRAMEWORK	=	AppKit OpenGL


vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra -fsanitize=address -g
IFLAG	=	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )
LFLAG	+=	$(foreach framework, $(FRAMEWORK), -framework $(framework) )

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

all	:		$(NAME)

$(OBJ_DIR)%.o:%.c $(HEADERS)		
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 
				

$(NAME):	install $(OBJ)
				$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ) -o $@

install :	
				@make -C libs/libft
				@make -C libs/minilibx

re-install :
				@make -C libs/libft re
				@make -C libs/minilibx re

show :
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
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re