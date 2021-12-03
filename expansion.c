/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:45:34 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/03 07:53:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*searchin_env(char *tmp, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		if (compaiiiire(tmp, env[i]))
			return (grab_value(env[i]));
	return (NULL);
}

int	eeexpand(char *a, int i, char **env, char **s)
{
	int		j;
	char	*tmp;
	char	*value;

	j = i + 1;
	while (a[++i] == '_' || (a[i] >= 48 && a[i] <= 57)
		|| (a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
		continue ;
	tmp = malloc ((i - j + 1) * sizeof(char));
	tmp[i - j] = '\0';
	fullfil(&tmp, a, j, i - j);
	value = searchin_env(tmp, env);
	if (value)
		add(s, value, 'f');
	free(tmp);
	return (i);
}

int	add_exit_status(int exit_status, char **s, int i)
{
	char	*b;

	b = get_string(exit_status);
	add(s, b, 'f');
	return (i + 2);
}

int	manage_squotes(char **s, char *a, int i)
{
	char	tab[2];

	if (a[i] == '\"')
		return (i + 1);
	tab[1] = '\0';
	while (a[++i] != '\'' && a[i])
	{
		tab[0] = a[i];
		add(s, tab, 'n');
	}
	return (i);
}

void	file_name(char *a, int exit_status, char **s, char **env)
{
	char	tab[2];
	char	i;

	i = 0;
	tab[1] = '\0';

	while (a[i])
	{
		if (should_add(a[i], a[i + 1]))
		{
			tab[0] = a[i++];
			add(s, tab, 'n');
		}
		else if (a[i] == '\'' || a[i] == '\"')
			i = manage_squotes(s, a, i);
		else if (a[i + 1] == '\'' || a[i + 1] == '\"')
			i = manage_squotes(s, a, i + 1);
		else if (a[i + 1] >= 48 && a[i + 1] <= 57)
			i = i + 2;
		else if (a[i + 1] == '?')
			i = add_exit_status(exit_status, s, i);
		else
			i = eeexpand(a, i, env, s);
	}
}
