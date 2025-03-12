# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juchene <juchene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 16:36:14 by aouichou          #+#    #+#              #
#    Updated: 2024/02/01 23:38:11 by juchene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ircserv
NAME_NF			=	$(NAME)_nf

SRCS_DIR		=	./srcs
OBJS_DIR		=	./objs
INCS_DIR		=	./incs

MAIN			=	./main.cpp
SRCS			=	$(shell find $(SRCS_DIR) -name "*.cpp")
OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o, $(SRCS))

CC				=	c++
CPP_STANDARD	=	-std=c++98
CFLAGS			=	-g -MMD -Wall -Wextra -Werror -I $(INCS_DIR) $(CPP_STANDARD)
NFLAGS			=	-g -MMD -I $(INCS_DIR)
MUTE			=	"@"

RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
BLUE 			=	\033[1;34m
RESET 			=	\033[0m
					
CREDITS			=	"\n                   ┏━━━┓┏━━━━┓    ┏━━┓┏━━━┓┏━━━┓                 \n" \
					"                  ┃┏━━┛┃┏┓┏┓┃    ┗┫┣┛┃┏━┓┃┃┏━┓┃                 \n" \
					"                  ┃┗━━┓┗┛┃┃┗┛     ┃┃ ┃┗━┛┃┃┃ ┗┛                 \n" \
					"                  ┃┏━━┛  ┃┃       ┃┃ ┃┏┓┏┛┃┃ ┏┓                 \n" \
					"                  ┃┃    ┏┛┗┓┏━━━┓┏┫┣┓┃┃┃┗┓┃┗━┛┃                 \n" \
					"                  ┗┛    ┗━━┛┗━━━┛┗━━┛┗┛┗━┛┗━━━┛                 \n" \
					"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \
					"━━━━━━━━━┃ Made in 42Paris by : \033[1;91aouichou  &&  juchene\033[m ┃━━━━━━━━━\n" \
					"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" \

all				:	$(OBJS) $(NAME) 
# make credit
# make head

nf				:	$(OBJS) $(NAME_NF)

# @ make head
$(NAME)			:	$(OBJS) $(MAIN)
	echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"
	echo "━━━━━━━━━┃ Made in 42Paris by : \033[1;91aouichou  &&  juchene\033[m ┃━━━━━━━━━"
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME)
	rm -rf $(NAME).d
	echo "$(BLUE)█████████████████████ Making ft_irc Server █████████████████████$(RESET)"
	echo $(CREDITS)
	echo "\033[32m$(NAME) created successfully !\033[0m"

$(NAME_NF)		:	$(OBJS) $(MAIN)
	echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"
	echo "━━━━━━━━━┃ Made in 42Paris by : \033[1;91aouichou  &&  juchene\033[m ┃━━━━━━━━━"
	$(CC) $(NFLAGS) $(OBJS) $(MAIN) -o $(NAME_NF)
	rm -rf $(NAME).d
	echo "$(BLUE)█████████████████████ Making ft_irc Server █████████████████████$(RESET)"
	echo $(CREDITS)
	echo "\033[32m$(NAME) created successfully !\033[0m"

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.cpp
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c $< -o $@

clean			:
	rm -rf $(OBJS_DIR)
	echo "\033[31m$(NAME) objects deleted successfully !\033[0m"
	echo "\033[31m$(NAME_NF) objects deleted successfully !\033[0m"

fclean			:	clean
	rm -rf $(NAME)
	rm -rf $(NAME_NF)
	echo "\033[31m$(NAME) deleted successfully !\033[0m"
	echo "\033[31m$(NAME_NF) deleted successfully !\033[0m"

re				:	fclean
					make all
					
credit:
	@echo "                  ┏━━━┓┏━━━━┓    ┏━━┓┏━━━┓┏━━━┓                 "
	@echo "                  ┃┏━━┛┃┏┓┏┓┃    ┗┫┣┛┃┏━┓┃┃┏━┓┃                 "
	@echo "                  ┃┗━━┓┗┛┃┃┗┛     ┃┃ ┃┗━┛┃┃┃ ┗┛                 "
	@echo "                  ┃┏━━┛  ┃┃       ┃┃ ┃┏┓┏┛┃┃ ┏┓                 "
	@echo "                  ┃┃    ┏┛┗┓┏━━━┓┏┫┣┓┃┃┃┗┓┃┗━┛┃                 "
	@echo "                  ┗┛    ┗━━┛┗━━━┛┗━━┛┗┛┗━┛┗━━━┛                 "
	@echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@echo "━━━━━━━━━┃ Made in 42Paris by : \033[1;91aouichou  &&  juchene\033[m ┃━━━━━━━━━"
	@echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# **************************************************************************** #

-include $(OBJS:.o=.d)

.PHONY			:	all clean fclean re credit head nf
