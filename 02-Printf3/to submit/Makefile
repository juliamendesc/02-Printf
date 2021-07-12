# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julcarva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 13:44:20 by julcarva          #+#    #+#              #
#    Updated: 2021/07/12 22:42:43 by julcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	= printf.h

CFLAGS	=	-Wall -Wextra -Werror

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=$(DIR_OBJS)%.o)

AR = ar -rcs

DIR_OBJS = obj/

SRCS	=	ft_conversion.c ft_conversion2.c ft_printf.c ft_utils.c ft_utils2.c ft_utils3.c

SRCS_BONUS	=	ft_conversion.c ft_conversion2.c ft_printf.c ft_utils.c ft_utils2.c ft_utils3.c

all:		$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)
		@echo "$(NAME) created and indexed"

$(DIR_OBJS)%.o: %.c
	gcc $(CFLAGS) -include $(HEADER) -c $< -o $@

$(OBJS):	| $(DIR_OBJS)
$(OBJS_BONUS):	| $(DIR_OBJS)
$(DIR_OBJS):
			mkdir $(DIR_OBJS)

clean:
			rm -rf $(DIR_OBJS)
			@echo "##### Removed lib object files #####"

fclean:		clean
			rm -f $(NAME)
			@echo "##### Removed $(NAME) #####"

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus