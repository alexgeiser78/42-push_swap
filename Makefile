# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 18:43:17 by ageiser           #+#    #+#              #
#    Updated: 2023/02/26 18:21:18 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
BLACK:=\033[1;30m"
RED:="\033[1;31m"
GREEN:=\033[1;32m"
YELLOW:=\033[1;33m"
BLUE:=\033[1;34m"
MAGENTA:=\033[1;35m"
CYAN:=\033\036[1;36m"
LIGHTGRAY:=\033[1;37m"
DARKGRAY:=\033[1;90m"
LIGHTRED:=\033[1;91m"
LIGHTGREEN:=\033[1;92m"
LIGHTYELLOW:=\033[1;93m"
LIGHTBLUE:=\033[1;94m"
LIGHTMAGENTA:=033[1;95m"
LIGHTCYAN:=033[1;96m"
WHITE:=033[1;97m"

#\033 = esacpe character
#"\[0m" removes atrributes (format and color)
#see all at https://misc.flogisoft.com/bash/tip_colors_and_formatting

#set
BOLD:=\033[1m"
DIM:=\033[2m"
UNDERLINED:=\033[4m"
BLINK:=\033[5m"
REVERSE:=\033[7m"
HIDDEN:=\033[8m"

#background
BBLACK:=\033[40m"
BRED:=\033[41m"
BGREEN:=\033[42m"
BYELLOW:=\033[43m"
BBLUE:=\033[44m"
BMAGENTA:=\033[45m"
BCYAN:=\033[46m"
BLIGHTGRAY:=\033[47m"
BDEFAULTBLACK:=\033[49m"
BDARKGRAY:=\033[100m"
BLIGHTRED:=\033[101m"
BLIGHTGREEN:=\033[102m"
BLIGHTYELLOW:=\033[103m"
BLIGHTBLUE:=\033[104m"
BLIGHTMAGENTA:=\033[105m"
BLIGHTCYAN:=\033[106m"
BWHITE:=\033[107m"

#----------------------------------------------------------------------

#$@ = target name //output
#$< = first dependencies //source
#$^ = dependecies list
#$? = dependecies list more recent than the target
#$* = filename without extensions

#---------------------------------------------------------------------

NAME = push_swap
#output name

#----------------------------------------------------------------------

CC = gcc
#compiler
#gcc = Linux
#clang = Mac

#----------------------------------------------------------------------

CFLAGS =  -c -Wall -Wextra -Werror
# -c = without linking. Don't link files together

#----------------------------------------------------------------------

SRC_DIR = src/
#sources directory

#----------------------------------------------------------------------

SRC_FILES = error_functions.c error_functions_suite.c \
	    general_function.c list_functions.c \
	    main.c push.c rev_rot.c rot.c swap.c 
# C files to compile

#----------------------------------------------------------------------

OBJ_DIR = obj/
#objects directory

#----------------------------------------------------------------------

OBJ = $(SRC_FILES:.c=.o)
#                                                                       to check and comment

#----------------------------------------------------------------------

SUB_DIR = obj/ps_srcs obj/c_srcs
#sub-directories                                                        to check

#----------------------------------------------------------------------

LIB_DIR = libft/
LIB = libft.a
#subdirectories for libraries                                            to check and add printf
#output of the librairies
#use the Makefile of the librairy to create the output

#----------------------------------------------------------------------

INCLUDE =   -I ./include/	\
#				-I $(LIB_DIR)
#library inclusion							  to check
# -I add .h file

#----------------------------------------------------------------------

RM = rm -f
#remove file

#----------------------------------------------------------------------

PS_SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
#add a prefix to the file, in this case: src/  ,   main.c                to check

#----------------------------------------------------------------------

PS_OBJ = $(addprefix $(OBJ_DIR), $(OBJ))
#add a prefix to the file, in this case: obj/  ,  main.o                  to check

#-----------------------------------------------------------------------

all : $(NAME)
#make rule, can be compaired to the main and follows all rules on by one   add $(OBJ_DIR)?

#-----------------------------------------------------------------------
$(OBJ_DIR)%.o	  : $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR) $(SUB_DIR)                    
			$(CC) -g $(CFLAGS) $(INCLUDE) $< -o $@
#pattern rules
#to build .o files we use the .c files
#@mkdir = sub directories creation 
#-p = intermediate directories creation. Without this option the directory
#must allready exist and. If it's not the case there won't be an error      to check all and subdir
#message. Repertories are created with 777 rights
# -g = generate debug information
# $< first dependencies(*.c)  -o write output to file  $@ target (*.o)

#-----------------------------------------------------------------------

$(LIB) :
		@$(MAKE) -C $(LIB_DIR)
		/bin/mv $(LIB_DIR)$(LIB) .
# . sert a dire ou l'on copie ce fichier soit dans le dossier parent		to check and comment
# 										is it necessary?

#-----------------------------------------------------------------------
$(NAME) : $(PS_OBJ)
	$(CC) $(CFLAGS) $(PS_OBJ) -o $(NAME)
#                                                                               to check and comment
#                                                                               add $(LIB) after the
#                                                                               first $(PS_OBJ)?

#-----------------------------------------------------------------------

clean : 
			for dir in $(SUB_DIR); do\
				@$(MAKE) clean -C $$dir;\
			done
			@/bin/rm -rf $(OBJ_DIR)
# remove targets
# for the directory in SUB_DIR -> we execute the command make clean 		to check and add (RM)
# 										-C ???

#-----------------------------------------------------------------------

fclean : clean
#		@$(MAKE) fclean -C $(LIB_DIR)
#		@$(RM) $(LIB)
		@$(RM) $(NAME)
#									to check and comment

#-----------------------------------------------------------------------

re : fclean all
#excute fclean and all so it destroys all previous and rebuild

#-----------------------------------------------------------------------

.PHONY : all clean fclean re
#for non-files targets, so doesn't look if it is up to date

#-----------------------------------------------------------------------
