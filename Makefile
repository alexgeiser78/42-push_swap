# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 18:43:17 by ageiser           #+#    #+#              #
#    Updated: 2023/02/25 18:56:26 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#nom de sortie

CC = gcc
#gcc = Linux
#clang = Mac

LIB_DIR = libft/
LIB = libft.a
#sous-dossier de la libft
#fichier de sortie de la libft
#se sert du makefile libft pour creer libft.a

SRC_DIR = srcs/
#dossier des sources

SRC_FILES = main.c sort_function.c push_swap.c
				
# fichiers c a compiler

OBJ_DIR = obj/
#dossier des objects

SUB_DIR = obj/ps_srcs obj/c_srcs
#sous-dossier des .c et .o a voir comment ca fonctionne

FLAG =  -c -Wall -Wextra -Werror
# -c = without linking. permet de ne pas lier des fichier entre eux

INCLUDE =   -I include/	\
				-I $(LIB_DIR)
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

$(LIB) :
		@$(MAKE) -C $(LIB_DIR)
		/bin/mv $(LIB_DIR)$(LIB) .
# a commenter
# . sert a dire ou l'on copie ce fichier soit dans le dossier parent		

$(NAME) : $(PS_OBJ) $(LIB)
#a commenter	


clean : 
			for dir in $(MODULES); do\
				@$(MAKE) clean -C $$dir;\
			done
			@/bin/rm -rf $(OBJ_DIR)
# a commenter
fclean : clean
		@$(MAKE) fclean -C $(LIB_DIR)
		@$(RM) $(LIB)
		@$(RM) $(NAME)
#a commenter			
re : fclean all

.PHONY : all clean fclean re
