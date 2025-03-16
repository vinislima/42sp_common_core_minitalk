# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 21:17:40 by vinda-si          #+#    #+#              #
#    Updated: 2025/03/13 21:02:32 by vinda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus
LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -g -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT_ARCHIVE)
		$(CC) $(CFLAGS) -g -o $@ $(CLIENT_OBJS) -L$(LIBFT_PATH) -lft

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT_ARCHIVE)
		$(CC) $(CFLAGS) -g -o $@ $(SERVER_OBJS) -L$(LIBFT_PATH) -lft

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS) $(LIBFT_ARCHIVE)
		$(CC) $(CFLAGS) -g -o $@ $(CLIENT_BONUS_OBJS) -L$(LIBFT_PATH) -lft

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS) $(LIBFT_ARCHIVE)
		$(CC) $(CFLAGS) -g -o $@ $(SERVER_BONUS_OBJS) -L$(LIBFT_PATH) -lft

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

clean:
		rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
		$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus


