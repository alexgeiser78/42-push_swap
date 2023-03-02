# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 18:43:17 by ageiser           #+#    #+#              #
#    Updated: 2023/03/02 13:44:25 by ageiser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#color
BLACK=\033[1;30m
RED =\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE:=033[1;34m
MAGENTA=\033[1;35m
CYAN=\033\036[1;36m
LIGHTGRAY=\033[1;37m
DARKGRAY=\033[1;90m
LIGHTRED=\033[1;91m
LIGHTGREEN=\033[1;92m
LIGHTYELLOW=\033[1;93m
LIGHTBLUE=\033[1;94m
LIGHTMAGENTA=033[1;95m
LIGHTCYAN=\033[1;96m
WHITE=\033[1;97m
NO_COLOR=\033[0m

#\033 = escape character
#\033[0m removes atrributes (format and color)
#see all at https://misc.flogisoft.com/bash/tip_colors_and_formatting

#set
BOLD=\033[1m
DIM=\033[2m
UNDERLINED=\033[4m
BLINK=\033[5m
REVERSE=\033[7m
HIDDEN=\033[8m

#background
BBLACK=\033[40m
BRED=\033[41m
BGREEN=\033[42m
BYELLOW=\033[43m
BBLUE=\033[44m
BMAGENTA=\033[45m
BCYAN=\033[46m
BLIGHTGRAY=\033[47m
BDEFAULTBLACK=\033[49m
BDARKGRAY=\033[100m
BLIGHTRED=\033[101m
BLIGHTGREEN=\033[102m
BLIGHTYELLOW=\033[103m
BLIGHTBLUE=\033[104m
BLIGHTMAGENTA=\033[105m
BLIGHTCYAN=\033[106m
BWHITE=\033[107m

#----------------------------------------------------------------------

#$@ = target name //output
#$< = first dependencies //source
#$^ = dependecies list
#$? = dependecies list more recent than the target
#$* = filename without extensions

#---------------------------------------------------------------------

CC = gcc
#compiler
#gcc = Linux
#clang = Mac

#----------------------------------------------------------------------

CFLAGS = -Wall -Wextra -Werror 
# -Wall   = -Wadress -Wcomment -Wformat -Wbool-compare -Wuninitialized
#           -Wunknown-pragmas -Wunused-value...		
# -Wextra = -Wsign-compare -Wtype-limits -pedantic...
# -Werror = transform warning into error

#----------------------------------------------------------------------

NAME = push_swap
#output name

#----------------------------------------------------------------------

SRC_DIR = src/
#sources directory

#----------------------------------------------------------------------

OBJ_DIR = obj/
#objects directory

#----------------------------------------------------------------------

SRC_FILES = error_functions.c error_functions_suite.c \
	    general_function.c list_functions.c \
	    main.c push.c rev_rot.c rot.c swap.c 
# C files to compile

#----------------------------------------------------------------------

TMP_SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
#add a prefix to the file, in this case: src/  ,   main.c               

#----------------------------------------------------------------------

OBJ = $(SRC_FILES:.c=.o)
#what obj is

#----------------------------------------------------------------------

TMP_OBJ = $(addprefix $(OBJ_DIR), $(OBJ))
#add a prefix to the file, in this case: obj/  ,  main.o                

#-----------------------------------------------------------------------

INCLUDE =   -I ./include/	
#library inclusion							
# -I add .h file

#----------------------------------------------------------------------

LIB_DIR = ./libft/
LIB = ./libft/libft.a
#subdirectories for libraries
#output of the librairies
#use the Makefile of the librairy to create the output

#----------------------------------------------------------------------

RM = rm -rf
#remove directory or file

#----------------------------------------------------------------------

all: makelib $(OBJ_DIR) $(NAME)
#make rule, can be compaired to the main and follows all rules one by onei
#

#-----------------------------------------------------------------------

makelib: 
	make -C $(LIB_DIR)
#compile the external librairy libft but don't generate libft.a

#-----------------------------------------------------------------------

$(OBJ_DIR)%.o	  : $(SRC_DIR)%.c  	
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
			@echo "$(GREEN)file compiled$(NO_COLOR)"
#pattern rules
#to build .o files we use the .c files
# -c = without linking. Don't link files together
# in case of bonuses it's important to put $(INCLUDE) beside $(SRC_DIR)%.c

#-----------------------------------------------------------------------

$(OBJ_DIR): 
	mkdir  $(OBJ_DIR)
#@mkdir = create the obj file if it not exist 
#-p = intermediate directories creation. Without this option the directory
#must allready exist. If it's not the case there won't be an error 
#message. Repertories are created with 777 rights. Useful only if 
#subdirectory is used

#-----------------------------------------------------------------------

$(NAME) : $(TMP_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(TMP_OBJ) -L ./libft/ -lft -o $(NAME)
	@echo "$(GREEN)librairy compiled and executable generated$(NO_COLOR)"
#
#library compilation function
#push_swap = obj/main.o ./libft/libft.a
#gcc -Wall -Wextra -Werror obj/main.o 
#-L = librairy search. In the directory ./libft/ 
#-l = search for library named ft. lib and .a are forgotten
#-o = output name                                                               

#-----------------------------------------------------------------------

clean : 
			$(RM) $(OBJ_DIR)
			$(MAKE) clean -C $(LIB_DIR)
			@echo "$(RED)objects (*.o) removed$(NO_COLOR)"
# remove targets
# delete the obj directory	
# delete the obj directory of the librairy also
# red color 									

#-----------------------------------------------------------------------

fclean : clean
		
		$(RM) $(LIB)
		$(RM) $(NAME)
		@echo "$(RED)library (*.a) and executable removed $(NO_COLOR)"
#removes the library (*.a)
#removes the output file push_swap
#red color

#-----------------------------------------------------------------------

re : fclean all
	@echo "$(YELLOW)make fclean  make all $(NO_COLOR)"
#execute fclean and all, so it destroys all previous and rebuild new

#-----------------------------------------------------------------------

.PHONY : all clean fclean re
#for non-files targets, so doesn't look if it is up-to-date

#-----------------------------------------------------------------------

