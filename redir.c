/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:53:57 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/03 02:48:00 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initi(t_add_red *c, int exit_status, char **env, t_red **red)
{
	c->env = env;
	c->exit_status = exit_status;
	c->red = red;
	red[0] = NULL;
}

void	get_last_node(t_red **j, t_red **red)
{
	if (red[0] == NULL)
	{
		red[0] = malloc(sizeof(t_red));
		*j = red[0];
	}
	else
	{
		*j = red[0];
		while((*j)->next)
			*j = (*j)->next;
		(*j)->next = malloc(sizeof(t_red));
		*j = (*j)->next;
	}
}

void	add_red(char *str, int *i, t_add_red c, int type)
{
	t_red	*j;
	
	get_last_node(&j, c.red);
	j->type = type;
	if (type == 1 || type == 3)
		c.red_file = get_arg(str, i, 0);
	else
		c.red_file = get_arg(str, i, 1);
	c.s = NULL;
	file_name(c.red_file, c.exit_status, &c.s, c.env);
	if (!c.s)
	{
		char a[2];
		a[0]= (char)130;
		a[1] = '\0';
		c.s = ft_strjoin(a, c.red_file);
	}
	j->name = c.s;
	j->next = NULL;
	free(c.red_file);
}

t_red	*redirections(char *str, int exit_status, char **env, int i)
{
	t_red		*red;
	t_add_red	c;
	int			sq;
	int			dq;

	sq = 0;
	dq = 0;
	initi(&c, exit_status, env, &red);
	while (str[++i])
	{
		if (str[i] == '\'')
			sq++;
		if (str[i] == '\"')
			dq++;
		if (str[i] == '>' && str[i + 1] == '>' && !(sq % 2) && !(dq % 2))
			add_red(str + i + 2, &i, c, 2);
		else if (str[i] == '>' && str[i + 1] != '>' && !(sq % 2) && !(dq % 2))
			add_red(str + i + 1, &i, c, 1);
		else if (str[i] == '<' && str[i + 1] == '<' && !(sq % 2) && !(dq % 2))
			add_red(str + i + 2, &i, c, 4);
		else if (str[i] == '<' && str[i + 1] != '<' && !(sq % 2) && !(dq % 2))
			add_red(str + i + 1, &i, c, 3);
	}
	return (red);
}
