/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:11 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/26 23:04:57 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//create a new linked list
t_cmd	*ft_lstnew(char **args, t_red *red)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->args = args;
	new->red = red;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	help_itoa(int n, int i)
{
	while (n)
	{
		n /= 10;
		i++;
	}
}

//ft_itoa
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 1;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	n = n * sign;
	help_itoa(n, i);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}


int	hold_s(int *dbl, int *j, int *i, char *s)
{
	if (s[*j] == '\'')
		(*dbl)++;
	(*i)++;
	(*j)++;
	return (0);
}
