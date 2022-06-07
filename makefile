# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alal-ali <alal-ali@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 00:28:30 by alal-ali          #+#    #+#              #
#    Updated: 2022/06/01 11:17:55 by alal-ali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

serverSRC = server.c serverlib.c
clientSRC =	client.c clientlib.c

SERVEROBJ = $(serverSRC:.c=.o)
CLIENTOBJ = $(clientSRC:.c=.o)

RM 		= 		rm -rf
CC 		= 		gcc
CFLAGS		= -Wall -Wextra -Werror

all : 		server client

server :	$(SERVEROBJ)
			$(CC) $(CFLAGS) $(SERVEROBJ) -o server

client : 	$(CLIENTOBJ)
			$(CC) $(CFLAGS) $(CLIENTOBJ) -o client

clean :
		$(RM) $(SERVEROBJ) $(CLIENTOBJ)
fclean :	clean
		$(RM) server client

re : 	fclean  all

.PHONY: all .c.o clean fclean re
