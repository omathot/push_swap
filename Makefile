# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omathot <omathot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 18:25:12 by oscarmathot       #+#    #+#              #
#    Updated: 2023/05/29 12:19:02 by omathot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------
#VARIABLES

NAME 	:= push_swap
SRC 	:= main.c stack.c push.c swap.c free_help.c rotate.c reverse_rotate.c hardsorts.c helpers.c \
			radix.c index.c ft_atol.c printers.c sort5.c long_atoi.c
OBJ 	:= $(SRC:.c=.o)
LIBFT_A	:= lib/libft/libft.a
PRINTF_A := lib/printf/libftprintf.a
CMP		:= gcc
FLAGS 	:=  -Werror -Wall -Wextra -g -I lib
# -Werror -Wall -Wextra

#---------------------------------
#FORMATTING AND FUN

clear_line = \033[K
move_up = \033[A
define prettycomp
	@printf "$(1)$(clear_line)\n"
	@$(1)
	@printf "$(move_up)"
endef

RED		:= \033[31m
GREEN 	:= \033[32m
YELLOW	:= \033[33m
BLUE	:= \033[38;5;87m
MAGENTA := \033[35m
CYAN	:= \033[36m
RESET	:= \033[0m

#---------------------------------
#RULES

all	: $(NAME)
		@echo "$(GREEN)Project built successfully !$(RESET)"
		@echo "$(YELLOW)Usage: push_swap <numbers>$(RESET)"

$(NAME) : $(OBJ) $(LIBFT_A) $(PRINTF_A) push_swap.h
		@echo "$(CYAN)Creating the executable...$(RESET)"
		@$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

%.o : %.c push_swap.h
		@echo "$(CYAN)Compiling...$(RESET) $<"
		$(call prettycomp, $(CMP) -c $(FLAGS) -o $@ $<)

$(LIBFT_A) : 
		@echo "$(BLUE)Building libft library...$(RESET)\n"
		$(call prettycomp, make -C lib/libft)

$(PRINTF_A) :
		@echo "$(BLUE)Building ft_printf library...$(RESET)\n"
		$(call prettycomp, @make -C lib/printf)

clean :
		@rm -f $(OBJ) ./lib/libft/libft.a
		@echo "$(GREEN)Cleaned up the artifacts !$(RESET)"

fclean :
		@rm -f $(NAME) $(OBJ)
		@echo "$(MAGENTA)Cleaned up executable !$(RESET)"

hardclean : 
		@make fclean
		@cd ./lib/libft && make clean
		@cd ./lib/libft && make fclean
		@cd ./lib/printf && make clean
		@cd ./lib/printf && make fclean
		@echo "$(MAGENTA)Cleaned up all built files!$(RESET)"

re : fclean all
	
.PHONY : clean fclean re hardclean