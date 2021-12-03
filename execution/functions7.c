/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:39 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/02 18:15:32 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

int	is_there_value2(char *env)
{
	int	i ;

	i = -1;
	while (env[++i])
		if (env[i] == '=' && env[i + 1])
			return (1);
	return (0);
}

int	get_value(char *a)
{
	int	i;
	int	k;
	int	sign;

	k = -1;
	i = 0;
	sign = 1;
	if (a[0] == '-' || a[0] == '+')
	{
		k++;
		if (a[0] == '-')
			sign = -1;
	}
	while (a[++k])
	{
		if (a[k] >= 48 && a[k] <= 57)
			i = i * 10 + (a[k] - 48);
		else
			return (-1);
	}
	if (sign == -1)
		return (0);
	return (i + 1);
}

void	change_shlvl(char **env)
{
	int		i;
	char	*a;

	if (!is_there_value2(*env))
	{
		free(*env);
		*env = copy_string("SHLVL=1");
		return ;
	}
	i = get_value(env[0] + 6);
	free (*env);
	if (i == -1)
		*env = copy_string("SHLVL=1");
	else if (i == 0)
		*env = copy_string("SHLVL=0");
	else
	{
		a = get_string(i);
		*env = ft_strjoin("SHLVL=", a);
		free(a);
	}
}

void	add_shlvl(char ***env)
{
	int		i;
	char	**new_env;

	i = -1;
	while (env[0][++i])
		if (compaire_arg_env(env[0][i], "SHLVL"))
			break ;
	if (env[0][i] != NULL)
		change_shlvl(env[0] + i);
	else
	{
		new_env = malloc((number(*env) + 2) * sizeof(char *));
		i = copy_old_env(new_env, *env);
		new_env[i] = copy_string("SHLVL=0");
		new_env[i + 1] = NULL;
		*env = new_env;
	}
}
