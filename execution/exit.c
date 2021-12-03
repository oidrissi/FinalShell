/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:20:18 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/01 22:51:57 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

int	check_args(char **args, int last_exit)
{
	int	i;

	if (args[0] == NULL)
		exit(last_exit);
	i = is_num(args[0]);
	if (!i)
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", args[0]);
		exit(255);
	}
	if (args[1] != NULL)
	{
		printf("exit\nminishell: exit: too many arguments\n");
		return (1);
	}
	printf("exit\n");
	exit(ft_atoi(args[0]));
}

int	check_args_2(char **args)
{
	int	i;

	if (args[0] == NULL)
		return (0);
	i = is_num(args[0]);
	if (!i)
	{
		printf("minishell: exit: %s: numeric argument required\n", args[0]);
		return (255);
	}
	if (args[1] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	return (ft_atoi(args[0]));
}

int	exxit(t_cmd cmd, int last_exit)
{
	if (cmd.prev == NULL && cmd.next == NULL)
		return (check_args(cmd.args + 1, last_exit));
	return (check_args_2(cmd.args + 1));
}
