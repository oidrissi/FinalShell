/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:22:23 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/01 22:57:19 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

void	add_cmd(char *cmd, char ***env)
{
	char	**new_env;
	int		i;

	new_env = malloc((number(*env) + 2) * sizeof(char *));
	i = copy_old_env(new_env, *env);
	new_env[i] = ft_strjoin("_=", cmd);
	new_env[i + 1] = NULL;
	*env = new_env;
}

void	initialize(t_xe *xe, char ***env, int last_xe)
{
	xe->env = env;
	xe->last_ex = last_xe;
}

int	ft_atoi(char *a)
{
	int				i;
	long long int	num;
	int				sign;

	i = -1;
	sign = 1;
	if (a[0] == '-' || a[0] == '+')
	{
		i++;
		if (a[0] == '-')
			sign = -1;
	}
	num = 0;
	while (a[++i])
		num = num * 10 + (a[i] - 48);
	return ((int)(sign * num));
}

int	is_num(char *a)
{
	int	i;

	i = -1;
	if (a[0] == '-' || a[0] == '+')
	{
		i++;
		if (a[1] == '\0')
			return (0);
	}
	while (a[++i])
		if (a[i] < 48 || a[i] > 57)
			return (0);
	return (1);
}
