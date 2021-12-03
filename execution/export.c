/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:13:14 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/03 02:07:53 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

void	ft_write(char *a, int output)
{
	int	i;

	i = -1;
	while (a[++i] != '=' && a[i])
		write(output, a + i, 1);
	if (a[i] == '=')
	{
		write(output, "=\"", 2);
		while (a[++i])
			write(output, a + i, 1);
		write(output, "\"", 1);
	}
}

void	show(char **env, int output)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		write(output, "declare -x ", 11);
		ft_write(env[i], output);
		write(output, "\n", 1);
	}
	free(env);
}

int	show_env(char **env, int input, int output)
{
	char	**sorted_env;
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	sorted_env = malloc((number(env) + 1) * sizeof(char *));
	copy_env(sorted_env, env);
	while (sorted_env[++i])
	{
		j = i;
		while (sorted_env[++j])
		{
			if (ft_compaire(sorted_env[i], sorted_env[j]))
			{
				tmp = sorted_env[j];
				sorted_env[j] = sorted_env[i];
				sorted_env[i] = tmp;
			}
		}
	}
	input = 0;
	show(sorted_env, output);
	return (1);
}

void	clean_header(t_argument **header, t_argument *p, t_argument *l)
{
	int	i;

	while (l->next)
	{
		p = l->next;
		while (1)
		{
			i = compaire_arg_env(p->argument, l->argument);
			if (i)
			{
				if (i == 2)
					l->argument = p->argument;
				p = delete_node(p, header);
			}
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

int	export(char **args, int input, int output, char ***env)
{
	int			i;
	char		**new_env;
	t_argument	*header;

	if (!args[0] && show_env(*env, input, output))
		return (0);
	are_args_ingood_form(args, &header, &i, 'e');
	if (!header)
		return (1);
	if (env[0][0])
		change_already_existed_env(&header, *env);
	if (!header && i)
		return (1);
	if (!header && !i)
		return (0);
	if (header->next)
		clean_header(&header, NULL, header);
	new_env = malloc((number(*env)
				+ nbr_remained_args(header) + 1) * sizeof(char *));
	add_new_env(new_env, &header, copy_old_env(new_env, *env));
	*env = new_env;
	if (i)
		return (1);
	return (0);
}
