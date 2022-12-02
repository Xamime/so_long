# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 16:49:29 by mdesrose          #+#    #+#              #
#    Updated: 2022/12/02 18:10:11 by mdesrose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		parsing.c \
		error.c \
		so_long_utils.c \
		display.c \
		init.c \
		move.c \
		display2.c


OBJ =		${SRC:.c=.o}
CC = clang
LIBFT_SRC = libft
LIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -Imlx_linux -Ilibft -fPIE -g
RM = rm -f
NAME = so_long

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_SRC)/$(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${LIBFT}: 
	make -C ${LIBFT_SRC} all

all : ${NAME}
		
clean:
		${RM} ${OBJ} 
		make clean -C ${LIBFT_SRC}

fclean: clean
		${RM} ${NAME} ${OBJ}
		make fclean -C ${LIBFT_SRC}

re : fclean all

.PHONY :  all clean fclean re