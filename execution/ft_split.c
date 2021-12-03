/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:30:44 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/21 11:57:19 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	numberofpointers(char const *s, char c)
{
	int		comp;
	int		i;

	comp = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
	{
		comp++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			comp++;
		i++;
	}
	return (comp);
}

static int	wordsnumber(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char	**freememorie(char **p, int j)
{
	while (j--)
		free(p[j]);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**memalloue;
	int		z;
	int		i;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	z = numberofpointers(s, c);
	memalloue = malloc((z + 1) * sizeof(char *));
	while (j < z)
	{
		i = 0;
		memalloue[j] = malloc((wordsnumber(s, c) + 1) * sizeof(char));
		if (!memalloue[j])
			return (freememorie(memalloue, j));
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
			memalloue[j][i++] = *s++;
		memalloue[j++][i] = '\0';
	}
	memalloue[j] = NULL;
	return (memalloue);
}
