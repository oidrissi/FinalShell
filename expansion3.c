/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:47:02 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 21:47:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_string(char *string)
{
	int		n;
	char	*new_string;
	int		i;

	i = -1;
	n = ft_strlen(string);
	new_string = malloc((n + 1) * sizeof(char));
	while (string[++i])
		new_string[i] = string[i];
	new_string[i] = '\0';
	return (new_string);
}

int	compaiiiire(char *argument, char *env)
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
