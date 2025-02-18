# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dias <dias@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:17:38 by dias              #+#    #+#              #
#    Updated: 2025/02/18 11:25:44 by dias             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C		= client
NAME_S		= server
BONUS_C		= client_bonus
BONUS_S		= server_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Mandatory part
MAND_DIR	= mandatory/
MAND_SRCS_C	= client.c ft_atoi.c ft_putnbr.c
MAND_SRCS_S	= server.c ft_atoi.c ft_putnbr.c
MAND_HEAD	= $(MAND_DIR)minitalk.h

MAND_OBJS_C	= $(addprefix $(MAND_DIR), $(MAND_SRCS_C:.c=.o))
MAND_OBJS_S	= $(addprefix $(MAND_DIR), $(MAND_SRCS_S:.c=.o))

# Bonus part
BONUS_DIR	= bonus/
BONUS_SRCS_C	= client_bonus.c ft_atoi.c ft_putnbr.c send.c
BONUS_SRCS_S	= server_bonus.c ft_atoi.c ft_putnbr.c write.c
BONUS_HEAD	= $(BONUS_DIR)minitalk_bonus.h

BONUS_OBJS_C	= $(addprefix $(BONUS_DIR), $(BONUS_SRCS_C:.c=.o))
BONUS_OBJS_S	= $(addprefix $(BONUS_DIR), $(BONUS_SRCS_S:.c=.o))

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(MAND_OBJS_C)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_S): $(MAND_OBJS_S)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_C) $(BONUS_S)

$(BONUS_C): $(BONUS_OBJS_C)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_S): $(BONUS_OBJS_S)
	$(CC) $(CFLAGS) $^ -o $@

$(MAND_DIR)%.o: $(MAND_DIR)%.c $(MAND_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c $(BONUS_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAND_OBJS_C) $(MAND_OBJS_S) $(BONUS_OBJS_C) $(BONUS_OBJS_S)

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(BONUS_C) $(BONUS_S)

re: fclean all

.PHONY: all bonus clean fclean re
