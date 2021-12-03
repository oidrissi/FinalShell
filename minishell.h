/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:51:07 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/26 23:03:17 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
#include <termios.h>
# include <readline/history.h>
# include <string.h>

typedef struct    s_red
{
	char            *name;
	int             type;
	struct s_red    *next;
}               t_red;

typedef struct s_add_red
{
	int		exit_status;
	char	**env;
	t_red	**red;
	char	*red_file;
	char	*s;
}				t_add_red;

typedef struct	s_exit
{
	int				status;
	int				exit;
}				t_exit;

typedef struct  s_cmd
{
	char    **args;
	t_red     *red;
	struct s_cmd *next;
	struct s_cmd *prev;
}               t_cmd;

t_cmd           *g_sh;

int     main(int ac, char **av, char **env);
int	    ft_strlen(char *s);
int	    is_builtin(char *s);
int     in_quotes(char *s, int pos);
char	*ft_strtrim(char *s);
char	*ft_strdup(char *s);
t_cmd	*ft_lstnew(char **args, t_red *red);
int		ft_strcmp(char *s1, char *s2);
void	free_split(char **s);
char	*ft_substr(char *s, int start, int len);
char	*get_token(char *s, int *pos, char del);
char	*parse_token(char *token );
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_itoa(int n);
char	**a_split(char *s, char d);
void	file_name(char *a, int exit_status, char **s, char **env);
char	*expand(char *s, char **env);
int		ft_strchr(char *s, int c);
char	*trim_whitespaces(char *s);
int		parse(char *s);
char	*ft_itoa(int n);
void	handlesig(int sig);
void	ignctl(void);
void	fill_sh(char *line, int exit_status, char **env);
char	*get_arg(char *str, int *i, int k);
char	**new_split(char *s,  char d);
char	*searchin_env(char *tmp, char **env);
int		eeexpand(char *a, int i, char **env, char **s);
int		add_exit_status(int exit_status, char **s, int i);
int		manage_squotes(char **s, char *a, int i);
t_red	*redirections(char *str, int exit_status, char **env, int i);
char	*get_string(int i);
int		should_add(char a, char b);
void	add(char **s, char *a, char c);
void	fullfil(char **tmp, char *a, int j, int k);
char	*grab_value(char *a);
int 	tab_len(char **s);
int		get_wordlen(char *s, int i, char del);
char	*copy_string(char *string);
int		compaiiiire(char *argument, char *env);
t_red	*init_red();
void	more_help2(int *dbl, int *j, int *i);
int     more_help(int *sgl, int *j, int *i, char *s);
int     hold_d(int *dbl, int *j, int *i, char *s);
int		hold_s(int *dbl, int *j, int *i, char *s);
void	hold2(int *i, int *c);
void	init(int *dbl, int *sgl, int *c, int *j);
void	execute_command(t_cmd *cmd, int *exit_status, char ***env);
void	change_env_to_heap(char ***env, int pwd, int oldpwd, int i);


#endif