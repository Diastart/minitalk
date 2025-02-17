# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dias <dinursul@student.42.it>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 12:48:17 by Dias              #+#    #+#              #
#    Updated: 2025/02/17 12:48:57 by Dias             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= client
SERVER_NAME	= server
BONUS_NAME	= client_bonus
SERVER_BONUS_NAME = server_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_PATH	= ./libft
PRINTF_PATH	= ./ft_printf
LIBFT		= $(LIBFT_PATH)/libft.a
PRINTF		= $(PRINTF_PATH)/libftprintf.a

SRCS		= client.c
SERVER_SRCS	= server.c
BONUS_SRCS	= client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

OBJS		= $(SRCS:.c=.o)
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

all: $(NAME) $(SERVER_NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(SERVER_NAME)

bonus: $(BONUS_NAME) $(SERVER_BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(BONUS_NAME)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(SERVER_BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	$(RM) $(OBJS) $(SERVER_OBJS) $(BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	$(RM) $(NAME) $(SERVER_NAME) $(BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
