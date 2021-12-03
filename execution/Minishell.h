/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:26:20 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/02 18:15:48 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <sys/stat.h>

typedef struct s_redirections
{
	char					*file;
	int						type;
	struct s_redirections	*next;
}				t_red;

typedef struct s_cmd
{
	char			**args;
	t_red			*red;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef struct s_heredoc
{
	int	heredoc_pipe_input_fd;
	int	index;
}				t_hdoc;

typedef struct s_argument
{
	char				*argument;
	int					index;
	struct s_argument	*next;
}				t_argument;

typedef struct s_xe
{
	char	***env;
	int		last_ex;
}				t_xe;

int				ft_strlen(const char *a);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(const char *a, const char *b);
int				ft_str_compare(const char *a, const char *b);
char			*get_input(void);
void			execute_command(t_cmd *cmd, int *exit_status, char ***env);
void			child_work(t_cmd *cmd, int *fdr, int *fdw, char **env);
void			heredoc(t_red *red, t_hdoc *hdoc);
void			print_open_failing_reason(char *file);
int				print_open_failing_reason_l(char *file, t_hdoc hdoc,
					int *input, int *output);
void			change_args_with_exit_status(char **args, int exit_status);
void			execute(char **arguments, char **env);
void			check_file_error(char *file);
int				check_file_error_l(char *file, t_hdoc hdoc,
					int *input, int *output);
int				get_input_output_from_red_l(t_red *red,
					int *input, int *output, int i);
int				shell_builtin(t_cmd *cmd, int *fdr, int *fdw, t_xe xe);
void			get_input_output(t_red *red, int *input, int *output);
void			setting_final_input(t_hdoc hdoc, int index, int *input);
void			last_step(char *dir, char **args, char **env);
int				export(char **args, int input, int output, char ***env);
char			*copy_string(char *string);
int				copy_old_env(char **new_env, char **env);
void			change_env_to_heap(char ***env, int pwd, int oldpwd, int i);
int				number(char **args);
int				nbr_remained_args(t_argument *header);
void			add_to_list(char *arg, t_argument **header);
void			are_args_ingood_form(char **args, t_argument **header,
					int *k, char c);
int				compaire_arg_env(char *argument, char *env);
t_argument		*delete_node(t_argument *node, t_argument **header);
void			change_env(char *arg, char **env);
void			change_already_existed_env(t_argument **header, char **env);
void			add_new_env(char **new_env, t_argument **header, int i);
int				export(char **args, int input, int output, char ***env);
int				ft_compaire(char *a, char *b);
int				unset(char **args, char ***env);
int				check_argfor_unset(char *args, int *k);
int				compaire_arg_env(char *argument, char *env);
void			copy_env(char **new_env, char **env);
int				ft_frree(t_argument **header);
void			keep_wanted_env(char **new_env, t_argument **header,
					char **env);
void			add_cmd(char *cmd, char ***env);
int				cd(char **args, char ***env);
void			initialize(t_xe *xe, char ***env, int last_xe);
int				exxit(t_cmd cmd, int last_exit);
int				is_num(char *a);
int				ft_atoi(char *a);
int				is_there_value(char *env);
void			add_shlvl(char ***env);
char			*get_string(int i);
#endif
