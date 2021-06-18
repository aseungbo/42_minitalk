# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 10:54:18 by seuan             #+#    #+#              #
#    Updated: 2021/06/18 12:26:59 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server

CLIENT	= client

CC		= gcc $(CFLAGS)

CLFAGS	= -Wall -Wextra -Werror

SER_SRC	= src/server.c \
			src/util.c \
			src/util2.c

CLI_SRC	= src/client.c \
			src/util.c \
			src/util2.c \


SER_SRC_OBJ = $(SER_SRC: .c=.o)

CLI_SRC_OBJ = $(CLI_SRC: .c=.o)

all :	fclean $(SER_SRC_OBJ) $(CLI_SRC_OBJ)
			$(CC) $(SER_SRC_OBJ) -I minitalk.h -o server
			$(CC) $(CLI_SRC_OBJ) -I minitalk.h -o client

clean :
		@rm -rf ./src/*.o

fclean : clean
		@rm -rf $(SERVER) $(CLIENT)

re : fclean all

.PHONY : bonus all fclean clean
