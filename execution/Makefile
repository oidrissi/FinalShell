# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/02 17:45:42 by zel-bagh          #+#    #+#              #
#    Updated: 2021/11/29 22:53:16 by zel-bagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini

SRC = Minishell.c \
	executing_commands.c \
	childprocess.c \
	heredoc.c \
	shell_builtin.c \
	managing_files_errors.c \
	execute_in_childprocess.c \
	ft_split.c \
	execute_in_childprocess2.c \
	export.c \
	unset.c \
	exit.c \
	cd.c \
	functions1.c \
	functions2.c \
	functions3.c \
	functions5.c \
	functions6.c \
	functions4.c \
	functions7.c

all : $(NAME)

$(NAME) : $(SRC)
	gcc -Wall -Wextra -Werror -lreadline $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean: clean

re : fclean all	