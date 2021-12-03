/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:48:45 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/03 05:33:54 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_whitespaces(char *s)
{
	int	i;
	int	len;
	char *tmp;
	
	i = 0;
	len = ft_strlen(s);
	if (!s || !*s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (i == len)
	{
		free(s);
		return (ft_strdup(""));
	}
	while (s[len - 1] == ' ')
		len--;
	tmp = ft_substr(s, i, len - i);
	free(s);
	return (tmp);
}

int	toomuch(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			count++;
			i++;
			if (count > 2)
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	in_quotes(char *s, int pos)
{
	int	j;
	int	indb;
	int	insgl;

	j = pos - 1;
	indb = 0;
	insgl = 0;
	while (j >= 0)
	{
		while (j >= 0 && (s[j] == '\'' || s[j] == '\"'))
		{
			if (s[j] == '\'')
				insgl++;
			else if (s[j] == '\"')
				indb++;
			j--;
		}
		j--;
	}
	if (indb % 2 == 0 && insgl % 2 == 0)
		return (1);
	return (0);
}

int	proper_quotes(char *s)
{
	int	i;
	int	sgl;
	int	dbl;
	int	len;
	int	j;

	len = ft_strlen(s);
	sgl = 0;
	dbl = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			sgl++;
		else if (s[i] == '\"')
			dbl++;
		i++;
	}
	if (dbl % 2 == 0 && sgl % 2 == 0)
		return (1);
	return (0);
}

int	parse(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (2);
	while (s[i])
	{
		if (s[i] == '|' && s[i + 1] == '|')
			return (0);
		i++;
	}
	if (s[0] == '|' || s[ft_strlen(s) - 1] == '|'
		|| s[ft_strlen(s) - 1] == '>' || s[ft_strlen(s) - 1] == '<')
		return (0);
	if (!proper_quotes(s))
		return (0);
	// if (!toomuch(s))
	// 	return (0);
	return (1);
}
