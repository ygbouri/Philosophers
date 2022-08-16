# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 20:27:38 by ygbouri           #+#    #+#              #
#    Updated: 2022/08/15 22:39:48 by ygbouri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo_m/philo.c philo_m/src/philoparssing.c philo_m/src/ft_lstadd_back.c\
		philo_m/src/ft_lstnew.c philo_m/src/ft_lstlast.c philo_m/src/philo_utils.c
		
		
OBJ = $(SRC:.c=.o)

SRCB = philo_b/philo_bo.c philo_bonus/src/philoparssingb.c philo_bonus/src/ft_lstadd_backb.c\
		philo_bonus/src/ft_lstnewb.c philo_bonus/src/ft_lstlastb.c philo_bonus/src/philo_utilsb.c

OBJB = $(SRCB:.c=.o)

CC = @gcc

NAME = philo
NAMEB = philo_bonus
CFLAGS = -Wall -Wextra -Werror
HEADER = philo_m/philo.h
HEADERB = philo_bonus/philob.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 
	@echo "done for philo"


clean :
	@rm -rf $(OBJ) 
	@rm -rf $(OBJB) 
	echo "clean"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEB)

bonus : $(NAMEB)

$(NAMEB) : $(OBJB) $(HEADERB) 
	$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB)
	@echo "done for philo_bonus"

re : fclean all

PHONY: all clean fclean re 