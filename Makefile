# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:44:11 by eabdelha          #+#    #+#              #
#    Updated: 2022/02/08 10:41:05 by eabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

UTLS_PATH = ./utils/
SRC_MAN_PATH = ./src_man/
SRC_BONUS_PATH = ./src_bonus/
GNL_PATH = ./get_next_line/

FOBJ_SRC = object_files_src
FOBJ_BONUS = object_files_bonus
UOBJ_SRC = object_files_utlis

OBJECT_PATH = ./object_files_src/
BOBJECT_PATH = ./object_files_bonus/
UOBJECT_PATH = ./object_files_utlis/

INCLUDE = $(SRC_MAN_PATH)pipex.h
BINCLUDE = $(SRC_BONUS_PATH)pipex_bonus.h
GNLINCLUDE = $(GNL_PATH)get_next_line.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC	=	pipex.c				\
		execute.c			\
		arrange_io.c		\
		exit_error.c	

USRC =	ft_split.c			\
		ft_strjoin.c		\
		ft_strnstr.c		\
		ft_putendl_fd.c	  	\
		ft_putstr_fd.c		

BSRC = 	pipex_bonus.c		\
		execute_bonus.c		\
		here_doc_bonus.c	\
		arrange_io_bonus.c	\
		exit_error_bonus.c	\
		here_doc_utils_bonus.c

GNL	= get_next_line.c		\
	  get_next_line_utils.c

OBJECTS = $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))
BOBJECTS = $(addprefix $(BOBJECT_PATH), $(BSRC:.c=.o))
UOBJECTS = $(addprefix $(UOBJECT_PATH), $(USRC:.c=.o))
GNLOBJECTS = $(addprefix $(BOBJECT_PATH), $(GNL:.c=.o))

.PHONY : all bonus clean fclean re $(NAME)

all: $(NAME)
 
$(NAME): $(FOBJ_SRC) $(UOBJ_SRC) $(OBJECTS) $(UOBJECTS)
	@echo linking mandatory object files...
	@$(CC) $(CFLAGS) $(OBJECTS) $(UOBJECTS) -o $(NAME)

bonus: $(FOBJ_BONUS) $(UOBJ_SRC) $(BOBJECTS) $(UOBJECTS) $(GNLOBJECTS)
	@echo linking bonus object files...
	@$(CC) $(CFLAGS) $(BOBJECTS) $(UOBJECTS) $(GNLOBJECTS) -o $(NAME)


$(OBJECT_PATH)%.o: $(SRC_MAN_PATH)%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BOBJECT_PATH)%.o: $(SRC_BONUS_PATH)%.c $(BINCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(UOBJECT_PATH)%.o: $(UTLS_PATH)%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BOBJECT_PATH)%.o: $(GNL_PATH)%.c $(GNLINCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(FOBJ_SRC) : 
	@mkdir $@

$(UOBJ_SRC) : 
	@mkdir $@

$(FOBJ_BONUS) : 
	@mkdir $@

clean:
	@rm -f $(OBJECTS) $(BOBJECTS) $(UOBJECTS)
	@rm -rf $(FOBJ_BONUS) $(FOBJ_SRC) $(UOBJ_SRC)

fclean: clean 
	@rm -f $(NAME)

re: fclean all
