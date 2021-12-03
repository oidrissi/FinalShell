/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_in_childprocess2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:32:15 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/28 18:45:08 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

void	add_to_listt(int index, t_argument **header)
{
	t_argument	*last;

	if (!*header)
	{
		*header = malloc(1 * sizeof(t_argument));
		(*header)->index = index;
		(*header)->next = NULL;
	}
	else
	{
		last = *header;
		while (last->next)
			last = last->next;
		last->next = malloc(1 * sizeof(t_argument));
		last->next->index = index;
		last->next->next = NULL;
	}
}

int	is_there_value(char *env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (env[i] == '=')
			return (1);
	return (0);
}

void	get_novalue_env(t_argument **header, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!is_there_value(env[i]))
			add_to_listt(i, header);
}

void	clean_env(char ***env)
{
	t_argument	*header;
	char		**new_env;
	int			j;

	header = NULL;
	get_novalue_env(&header, *env);
	if (!header)
		return ;
	j = number(*env) - nbr_remained_args(header) + 1;
	new_env = malloc(j * sizeof(char *));
	new_env[j - 1] = NULL;
	keep_wanted_env(new_env, &header, *env);
	*env = new_env;
}

void	last_step(char *dir, char **args, char **env)
{
	clean_env(&env);
	add_cmd(dir, &env);
	execve(dir, args, env);
}
