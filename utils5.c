/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 07:27:42 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/02 07:48:21 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hold2(int *i, int *c)
{
	*i = *i + 1;
	*c = *c + 1;
}

void	init(int *dbl, int *sgl, int *c, int *j)
{
	*dbl = 0;
	*sgl = 0;
	*c = 0;
	*j = 0;
}

int	more_help(int *sgl, int *j, int *i, char *s)
{
	*sgl = *sgl + 1;
	*j = *i + 1;
	if (!s[*j])
		return (0);
	return (1);
}

void	more_help2(int *dbl, int *j, int *i)
{
	*dbl = *dbl + 1;
	*j = *i + 1;
}

int	hold_d(int *dbl, int *j, int *i, char *s)
{
	if (s[*j] == '\"')
		(*dbl)++;
	(*i)++;
	(*j)++;
	return (0);
}
