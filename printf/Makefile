# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 14:18:16 by tnakamur          #+#    #+#              #
#    Updated: 2020/08/03 20:27:34 by tnakamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAG = gcc -Wall -Wextra -Werror

SRC = ft_convert.c ft_printf.c ft_output_num.c ft_output_s.c ft_utils.c \
	ft_utils_2.c ft_join.c ft_flag.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all
