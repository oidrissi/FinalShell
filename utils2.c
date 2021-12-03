/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:04:54 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/26 12:05:05 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

int	ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	tab_len(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	get_wordlen(char *s, int i, char del)
{
	int	dbl;
	int	sgl;
	int	c;
	int	j;

	init(&dbl, &sgl, &c, &j);
	while (i < ft_strlen(s))
	{
		if (s[i] == '\'')
		{
			if (!more_help(&sgl, &j, &i, s))
				return (0);
			while (s[j])
				c = hold_s(&dbl, &j, &i, s) + c + 1;
		}
		if (s[i] == '\"')
		{
			more_help2(&dbl, &j, &i);
			while (s[j])
				c = hold_d(&dbl, &j, &i, s) + c + 1;
		}
		hold2(&i, &c);
	}
	return (c);
}
