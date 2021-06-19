# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 10:54:18 by seuan             #+#    #+#              #
#    Updated: 2021/06/19 16:37:20 by seuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server

CLIENT	= client

CC		= gcc $(CFLAGS)

RM		= rm -rf

CLFAGS	= -Wall -Wextra -Werror

SER_SRC	= src/server.c \
			src/util.c \
			src/util2.c

CLI_SRC	= src/client.c \
			src/util.c \
			src/util2.c \


SER_SRC_OBJ = $(SER_SRC:.c=.o)

CLI_SRC_OBJ = $(CLI_SRC:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER): $(SER_SRC_OBJ)
	$(CC) $(SER_SRC_OBJ) -I minitalk.h -o $(SERVER)

$(CLIENT): $(CLI_SRC_OBJ)
	$(CC) $(CLI_SRC_OBJ) -I minitalk.h -o $(CLIENT)

clean :
		$(RM) ./src/*.o

fclean : clean
		$(RM) $(SERVER) $(CLIENT)

re : fclean clean all

.PHONY : all fclean clean re
