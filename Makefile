# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:15:33 by bmenant           #+#    #+#              #
#    Updated: 2020/01/06 15:39:17 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = ft_atoi.c \
	  ft_absolute.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_itoa_xl.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putstr_w.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strchri.c \
	  ft_strchrstr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strjoinfree.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strlen_w.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strsubfree.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c

FLAGS =			-Wall -Wextra -Werror

SRC_FILE =		./src/
OBJ_FILE =		./obj/

OBJ =			$(SRC:.c=.o)

SRCS =			$(addprefix $(SRC_FILE),$(SRC))
OBJS =			$(addprefix $(OBJ_FILE),$(OBJ))

all: $(NAME)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c	
	@mkdir $(OBJ_FILE) 2> /dev/null || true
	@$(CC) -c $(FLAGS) -o $@ $<
	@echo "$@\r				$(OK)"

$(NAME): $(OBJS)
	@ echo "libft build in progress ..."
	@ ar rc libft.a $(OBJS)
	@ echo "\n \033[92mLibrary done\033[0m \n"

clean:
	@ /bin/rm -Rf $(OBJ_FILE)
	@ echo "\033[92mObjects erased\033[0m"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ echo "\033[92mLibrary erased\033[0m"

re: fclean all

.PHONY : all $(NAME) clean fclean all
