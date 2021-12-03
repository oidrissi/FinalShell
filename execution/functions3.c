/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:41:51 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/01 23:28:52 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

t_argument	*delete_node(t_argument *node, t_argument **header)
{
	t_argument	*p;

	if (node == *header)
	{
		*header = (*header)->next;
		free(node);
		return (*header);
	}
	else
	{
		p = *header;
		while (p->next != node)
			p = p->next;
		p->next = node->next;
		free(node);
		return (p->next);
	}
}

void	change_env(char *arg, char **env)
{
	free(env[0]);
	env[0] = copy_string(arg);
}

void	change_already_existed_env(t_argument **header, char **env)
{
	int			i;
	int			j;
	t_argument	*p;

	p = *header;
	while (1)
	{
		i = -1;
		while (env[++i])
		{
			j = compaire_arg_env(p->argument, env[i]);
			if (j != 0)
			{
				if (j == 2)
					change_env(p->argument, env + i);
				p = delete_node(p, header);
				break ;
			}
			if (!env[i + 1])
				p = p->next;
		}
		if (!p)
			break ;
	}
}

void	add_new_env(char **new_env, t_argument **header, int i)
{
	t_argument	*p;

	p = *header;
	while (1)
	{
		new_env[i++] = copy_string(p->argument);
		p = delete_node(p, header);
		if (!p)
			break ;
	}
	new_env[i] = NULL;
}

void	copy_env(char **new_env, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	new_env[i] = NULL;
}
