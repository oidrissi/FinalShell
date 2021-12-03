/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:40:10 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 15:02:34 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

int	check_argfor_unset(char *args, int *k)
{
	int	j;

	j = -1;
	while (args[++j])
	{
		if ((j == 0 && args[j] >= 48 && args[j] <= 57)
			|| ((args[j] < 48 || args[j] > 57)
				&& (args[j] < 65 || args[j] > 90)
				&& (args[j] < 97 || args[j] > 122)
				&& args[j] != '_'))
		{
			printf("Minishell: unset: `%s': not a valid identifier\n", args);
			*k = 1;
			return (0);
		}
	}
	return (1);
}

int	ft_frree(t_argument **header)
{
	t_argument	*p;
	t_argument	*k;

	p = *header;
	while (1)
	{
		k = p->next;
		free(p);
		if (!k)
			break ;
		p = k;
	}
	*header = NULL;
	return (1);
}

void	ft_free(char *a, char *b)
{
	free(a);
	free(b);
}

char	*get_key(char *p)
{
	int		i;
	char	*a;

	i = 0;
	while (p[i] != '=' && p[i])
		i++;
	a = malloc((i + 1) * sizeof(char));
	i = -1;
	while (p[++i] != '=' && p[i])
		a[i] = p[i];
	a[i] = '\0';
	return (a);
}

int	ft_compaire(char *a, char *b)
{
	char	*ta;
	char	*tb;
	int		i;

	ta = get_key(a);
	tb = get_key(b);
	i = -1;
	while (ta[++i] != '\0' || tb[i] != '\0')
	{
		if (ta[i] < tb[i])
		{
			ft_free(ta, tb);
			return (0);
		}
		if (ta[i] > tb[i])
		{
			ft_free(ta, tb);
			return (1);
		}
	}
	ft_free(ta, tb);
	return (2);
}
