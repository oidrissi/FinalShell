/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:46:00 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 23:09:03 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_string(int i)
{
	int		n;
	int		save;
	char	*s;

	n = 1;
	save = i;
	while ((i / 10) != 0)
	{
		n++;
		i = i / 10;
	}
	s = malloc((n + 1) * sizeof(char));
	s[n] = '\0';
	while ((save / 10) != 0)
	{
		s[--n] = (save % 10) + 48;
		save = save / 10;
	}
	s[--n] = save + 48;
	return (s);
}

int	should_add(char a, char b)
{
	if ((a == '$' && (b < 48 || b > 57) && (b < 65 || b > 90)
			&& (b < 97 || b > 122) && b != '_' && b != '?'
			&& b != '\'' && b != '\"') || (a != '$' && a != '\'' && a != '\"'))
		return (1);
	return (0);
}

void	add(char **s, char *a, char c)
{
	char	*tmp;

	if (!*s)
		*s = "";
	tmp = *s;
	*s = ft_strjoin(*s, a);
	if (*tmp != '\0')
		free(tmp);
	if (c == 'f')
		free(a);
}

void	fullfil(char **tmp, char *a, int j, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		tmp[0][i] = a[j++];
}

char	*grab_value(char *a)
{
	int	i;

	i = -1;
	while (a[++i] != '=' && a[i])
		continue ;
	if (!a[i] || (a[i] == '=' && a[i + 1] == '\0'))
		return (NULL);
	return (copy_string(a + i + 1));
}
