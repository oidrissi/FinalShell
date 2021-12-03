# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 19:53:07 by oidrissi          #+#    #+#              #
#    Updated: 2021/11/26 12:05:34 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LDFLAGS= -L /Users/$(USER)/goinfre/$(USER)/.brew/opt/readline/lib
CPPFLAGS= -I /Users/$(USER)/goinfre/$(USER)/.brew/opt/readline/include
READLINE = -lreadline -fsanitize=address -g $(LDFLAGS) $(CPPFLAGS)
FLAGS = $(READLINE)
NAME = hell420

SRC = minishell.c\
		utils.c\
		utils2.c\
		utils3.c\
		utils4.c\
		methods.c\
		expansion.c\
		expansion2.c\
		expansion3.c\
		sigs.c\
		redir.c\
		init.c\
		utils5.c\
	execution/executing_commands.c \
	execution/childprocess.c \
	execution/heredoc.c \
	execution/shell_builtin.c \
	execution/managing_files_errors.c \
	execution/execute_in_childprocess.c \
	execution/ft_split.c \
	execution/execute_in_childprocess2.c \
	execution/export.c \
	execution/unset.c \
	execution/exit.c \
	execution/cd.c \
	execution/functions1.c \
	execution/functions2.c \
	execution/functions3.c \
	execution/functions5.c \
	execution/functions6.c \
	execution/functions4.c \
	execution/functions7.c



all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
re: fclean all