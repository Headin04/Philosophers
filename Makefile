# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:42:57 by ode-cleb          #+#    #+#              #
#    Updated: 2023/06/21 17:04:29 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

		#COMMAND#

CC				= cc
MKDIR			= mkdir -p
RM				= rm -rf

		#SOURCES#

C_DIR			= src
C_FILES			= main.c\

#C_FILES_BONUS	=

SRCS			= $(patsubst %, $(C_DIR)/%, $(C_FILES))
#SRCS_BONUS		= $(patsubst %, $(C_DIR)/%, $(C_FILES_BONUS))

		#OBJECTS#

O_DIR			= objs
O_FILES			= $(C_FILES:.c=.o)
#O_FILES_BONUS	= $(C_FILES_BONUS:.c=.o)
OBJS			= $(patsubst %, $(O_DIR)/%, $(O_FILES))
#OBJS_BONUS		= $(patsubst %, $(O_DIR)/%, $(O_FILES_BONUS))

		#FLAGS#

FLAGS			= -Wall -Wextra -Werror

ifeq ($(debug), true)
	FLAGS += -fsanitize=address,undefined -g3
endif

		#INCLUDES#

INCLUDES		= -I ./include

		#RULES#

all: ${NAME}

$(O_DIR):
				$(MKDIR) $(O_DIR)

$(O_DIR)/%.o: $(C_DIR)/%.c
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(O_DIR) $(OBJS)
				$(CC) $(OBJS) $(FLAGS) -o $@

#bonus: $(O_DIR) $(OBJS_BONUS) $(LIBFTPRINTF) $(MLX)
#				$(CC) $(OBJS_BONUS) $(FLAGS) $(MFLAGS) $(LIBFTPRINTF) $(MLX) -o $@

clean :
				$(RM) $(O_DIR)

fclean :
				$(RM) $(O_DIR)
				$(RM) $(NAME)
#				$(RM) bonus

re : fclean all

.PHONY: all clean fclean re 
