/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:01:58 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/26 11:49:47 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
			i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		ft_strncmp(char *s1, char *s2, int n)
{
	int i;
	
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strtrim(char *s)
{
	int i;
	int len;
	char *ret;
	int j;

	i = 0;
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	j = 0;
	while (s[i] != '\0')
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return ret;
}

char	*ft_strdup(char *s)
{
	int i;
	int len;
	char *ret;

	i = 0;
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret || len == 0)
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}
