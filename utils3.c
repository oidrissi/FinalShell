/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:56:59 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/03 07:57:14 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg(char *str, int *i, int k)
{
	int		compt;
	int		compt2;
	char	*arg;

	compt = 0;
	while (str[compt] == ' ')
		compt++;
	compt2 = compt;
	while (str[compt] != ' ' && str[compt]
		&& str[compt] != '>' && str[compt] != '<')
		compt++;
	arg = (char *)malloc(sizeof(char) * (compt - compt2 + 1));
	if (!arg)
		return (NULL);
	compt = compt2;
	compt2 = 0;
	while (str[compt] && str[compt] != ' '
		&& str[compt] != '>' && str[compt] != '<')
		arg[compt2++] = str[compt++];
	arg[compt2] = '\0';
	*i += compt + k;
	return (arg);
}

char	**realloc_str(char **s, char *t)
{
	char	**ret;
	int		len;
	int		i;

	i = 0;
	len = tab_len(s);
	ret = (char **)malloc(sizeof(char *) * (len + 2));
	if (s == NULL)
	{
		ret[0] = ft_strdup(t);
		ret[1] = NULL;
		return (ret);
	}
	while (s[i] != NULL)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = ft_strdup(t);
	ret[i + 1] = NULL;
	return (ret);
}

int	is_alnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*get_token(char *s, int *pos, char del)
{
	int		i;
	int		len;
	int		word_len;
	char	*ret;
	int		c;

	c = 0;
	i = *pos;
	len = ft_strlen(s);
	word_len = get_wordlen(s, *pos, del);
	ret = (char *)malloc(sizeof(char) * (word_len + 1));
	while (i < len && c < word_len)
	{
		if ((i == len || s[i] == del) && in_quotes(s, i))
			break ;
		ret[c] = s[i];
		i++;
		c++;
	}
	*pos = i;
	ret[c] = '\0';
	return (ret);
}

char	**a_split(char *s, char d)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == d)
			i++;
		else
		{
			ret[j] = get_token(s, &i, d);
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}

char	**new_split(char *s, char d)
{
	char	**ret;
	char	*b;
	int		i;
	int		len;
	// static int save;
	ret = NULL;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '>' || s[i] == '<')
			break ;
		b = get_token(s, &i, d);
		if (b != '\0' || *b == '>' || *b == '<')
			ret = realloc_str(ret, b);
		i++;
		free(b);
	}
	//ret[i] = NULL;
	// i = 0;
	// while (ret[i])
	// {
	// 	printf("|%s|\n", ret[i]);
	// 	i++;
	// }
	// if (save != 0)
	// 	exit(0);
	// save++;
	// free(s);
	return (ret);
}
