# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szubair <szubair@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 16:17:34 by szubair           #+#    #+#              #
#    Updated: 2022/06/26 16:17:34 by szubair          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

serverSRC = server.c server_utils.c
serverBSRC = server_bonus.c server_utils_bonus.c
clientSRC =	client.c client_utils.c
clientBSRC = client_bonus.c client_utils_bonus.c

SERVEROBJ = $(serverSRC:.c=.o)
SERVERBOBJ = $(serverBSRC:.c=.o)
CLIENTOBJ = $(clientSRC:.c=.o)
CLIENTBOBJ = $(clientBSRC:.c=.o)

RM 		= 		rm -rf
CC 		= 		gcc
CFLAGS		= -Wall -Wextra -Werror

all : 		server client


server :	$(SERVEROBJ)
			$(CC) $(CFLAGS) $(SERVEROBJ) -o server

server_bonus :	$(SERVERBOBJ)
			$(CC) $(CFLAGS) $(SERVERBOBJ) -o server_bonus

client : 	$(CLIENTOBJ)
			$(CC) $(CFLAGS) $(CLIENTOBJ) -o client

client_bonus : 	$(CLIENTBOBJ)
			$(CC) $(CFLAGS) $(CLIENTBOBJ) -o client_bonus

clean :
		$(RM) $(SERVEROBJ) $(CLIENTOBJ) $(SERVERBOBJ) $(CLIENTBOBJ)
fclean :	clean
		$(RM) server client server_bonus client_bonus

re : 	fclean  all

bonus : client_bonus server_bonus

.PHONY: all clean fclean re bonus
