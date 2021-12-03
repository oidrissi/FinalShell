/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:43:06 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 22:32:37 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

int	nbr_remained_args(t_argument *header)
{
	int	n;

	n = 1;
	while (header->next)
	{
		n++;
		header = header->next;
	}
	return (n);
}

void	add_to_list(char *arg, t_argument **header)
{
	t_argument	*last;

	if (!*header)
	{
		*header = malloc(1 * sizeof(t_argument));
		(*header)->argument = arg;
		(*header)->next = NULL;
	}
	else
	{
		last = *header;
		while (last->next)
			last = last->next;
		last->next = malloc(1 * sizeof(t_argument));
		last->next->argument = arg;
		last->next->next = NULL;
	}
}

int	check_argfor_export(char *args, int *k)
{
	int	j;

	j = -1;
	while (args[++j] != '=' && args[j])
	{
		if ((j == 0 && args[j] >= 48 && args[j] <= 57) || (
				(args[j] < 48 || args[j] > 57) && (args[j] < 65
					|| args[j] > 90) && (args[j] < 97 || args[j] > 122)
				&& args[j] != '_'))
		{
			printf("Minishell: export: `%s': not a valid identifier\n", args);
			*k = 1;
			return (0);
		}
	}
	if (args[0] == '=')
	{
		printf("Minishell: export: `%s': not a valid identifier\n",
			args);
		*k = 1;
		return (0);
	}
	return (1);
}

void	are_args_ingood_form(char **args, t_argument **header, int *k, char c)
{
	int	i;

	i = -1;
	*k = 0;
	*header = NULL;
	while (args[++i])
	{
		if (c == 'e')
		{
			if (check_argfor_export(args[i], k))
				add_to_list(args[i], header);
		}
		else if (c == 'u')
		{
			if (check_argfor_unset(args[i], k))
				add_to_list(args[i], header);
		}
	}
}

int	compaire_arg_env(char *argument, char *env)
{
	int	j;
	int	k;

	j = -1;
	k = -1;
	while (env[++j] != '=' && env[j] && argument[++k] != '=' && argument[k])
		if (env[j] != argument[k])
			break ;
	if ((!env[j] || env[j] == '=') && (!argument[j] || argument[j] == '='))
	{
		if (argument[j] == '=')
			return (2);
		return (1);
	}
	return (0);
}
