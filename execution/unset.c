/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:52:42 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 15:24:39 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

void	keep_existed_env_inheader(t_argument **header, char **env)
{
	int			i;
	t_argument	*p;

	if (!env[0] && ft_frree(header))
		return ;
	p = *header;
	while (1)
	{
		i = -1;
		while (env[++i])
		{
			if (compaire_arg_env(p->argument, env[i]))
			{
				p->index = i;
				p = p->next;
				break ;
			}
			if (!env[i + 1])
				p = delete_node(p, header);
		}
		if (!p)
			break ;
	}
}

void	clean_header_unset(t_argument **header, t_argument *p, t_argument *l)
{
	while (l->next)
	{
		p = l->next;
		while (1)
		{
			if (l->index == p->index)
				p = delete_node(p, header);
			else
				p = p->next;
			if (!p)
				break ;
		}
		l = l->next;
		if (!l)
			break ;
	}
}

int	is_it_in_header(int i, t_argument *header)
{
	while (1)
	{
		if (header->index == i)
			return (1);
		header = header->next;
		if (!header)
			return (0);
	}
}

void	keep_wanted_env(char **new_env, t_argument **header, char **env)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (env[++i])
	{
		if (!is_it_in_header(i, *header))
			new_env[++j] = env[i];
		else
			free(env[i]);
	}
	free(env);
	ft_frree(header);
}

int	unset(char **args, char ***env)
{
	t_argument	*header;
	char		**new_env;
	int			i;
	int			j;

	if (!args[0])
		return (0);
	are_args_ingood_form(args, &header, &i, 'u');
	if (!header)
		return (1);
	keep_existed_env_inheader(&header, *env);
	if (!header && i)
		return (1);
	if (!header && !i)
		return (0);
	if (header->next)
		clean_header_unset(&header, NULL, header);
	j = number(*env) - nbr_remained_args(header) + 1;
	new_env = malloc(j * sizeof(char *));
	new_env[j - 1] = NULL;
	keep_wanted_env(new_env, &header, *env);
	*env = new_env;
	if (i)
		return (1);
	return (0);
}
