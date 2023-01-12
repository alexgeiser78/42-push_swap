# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 12:20:33 by ageiser           #+#    #+#              #
#    Updated: 2023/01/12 17:23:19 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
#maybe clang

LIB_DIR = libft/
LIB = libft.a

SRC_DIR = srcs/
#dossier des sources

SRC_FILES = main.c
# fichiers c 

OBJ_DIR = obj/
#dossier des objects

SUB_DIR = obj/ps_srcs obj/c_srcs
#sous-dossier des .c et .o

FLAG =  -c -Wall -Wextra -Werror
# -c = without linking. permet de ne pas lier des fichier entre eux

INCLUDE =   -I include/
#			-I $(LIB_DIR)
# -I quand ca se passe dans un autre dossier que celui ou se trouve le makefile

RM = rm -f

PS_SRCS = $(addprefix $(DIR), $(SRC_FILES))
#a commenter
PS_OBJ = $(PS_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)
#a commenter
all : $(NAME)

obj/%.o	  : srcs/%.c
			@mkdir -p $(OBJ_DIR) $(SUB_DIR)
			$(CC) -g $(FLAG) $(INCLUDE) $< -o $@
#creation des sous-dossiers. -p = creation de repertoire intermediaire. sans cette option, 
#le dossier doit deja exister. En plus, avec -p si ce n'est pas le cas, il n'y aura pas de 
#message d'erreur. Les annuaires sont crees avec des droits 777
# -g = generate debug information
# $< nom premiere dependance  -o write output to file  $@ nom cible

$(NAME) : $(PS_OBJ) $(LIB)
#a commenter	
clean : rm -rf $(OBJ_DIR)

fclean : clean
			@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
