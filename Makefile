# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#              #
#    Updated: 2020/02/02 20:05:30 by gtapioca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap_1.c\
			push_swap_2.c\
			push_swap_3.c\
			push_swap_4.c\
			push_swap_5.c\
			push_swap_6.c\
			push_swap_7.c\
			push_swap_8.c\
			push_swap_9.c\
			push_swap_10.c\
			push_swap_11.c\
			push_swap_12.c\
			push_swap_14.c\
			push_swap_15.c\
			push_swap_bonus_1.c\

CHECKER = 	checker_1.c\
			checker_2.c\
			checker_3.c\
			checker_4.c\
			checker_5.c\
			checker_6.c\
			get_next_line.c\

LIBFT = ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_lstmap.c\

VPATH = src/push_swap:src/checker:src/libft

CHECKER_OBJ = $(CHECKER:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)

all: $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT_OBJ)
	gcc -Wall -Wextra -Werror -o checker $(CHECKER_OBJ) $(LIBFT_OBJ) -Iincludes
	gcc -Wall -Wextra -Werror -o push_swap $(PUSH_SWAP_OBJ) $(LIBFT_OBJ) -Iincludes

%.o : %.c 
	gcc -Wall -Wextra -Werror -c -Iincludes $?

clean:
	rm -rf $(CHECKER_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -rf push_swap checker

re: fclean all
