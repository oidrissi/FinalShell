/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:54:47 by oidrissi          #+#    #+#             */
/*   Updated: 2021/12/03 07:53:56 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	boucle_2(char **s, char *expanded, int status, char **env)
{
	int	j;

	j = -1;
	// while (s[++j])
	// {
	// 	printf("%s\n", s[j]);
	// 	exit(0);
	// 	/* code */
	// }
	
	while (s[++j])
	{
		expanded = NULL;
		// printf("%s\n", s[j]);
		file_name(s[j], status, &expanded, env);
		if (expanded)
		{
			//free(s[j]);
			s[j] = ft_strdup(expanded);
		}
		else
		{
			//free(s[j]);
			//s[j] = malloc(sizeof(char));
			s[j] = ft_strdup("");
		}
	}
}

void	free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

t_cmd	*fill_sh(char *line, int exit_status, char **env)
{
	char	**args;
	int		i;
	int		j;
	char	*expanded = NULL;
	t_cmd	*cmd;

	i = -1;
	args = new_split(line, '|');
	while (args[++i])
	{
		expanded = NULL;
		if (i == 0)
		{
			g_sh = ft_lstnew(new_split(ft_strtrim(args[i]), ' '), \
			redirections(args[i], exit_status, env, -1));
			cmd = g_sh;
		}
		else
		{
			cmd->next = ft_lstnew(new_split(ft_strtrim(args[i]), ' '), \
			redirections(args[i], exit_status, env, -1));
			cmd->next->prev = cmd;
			cmd = cmd->next;
		}
		// while(1);
		boucle_2(cmd->args, expanded, exit_status, env);
		// while (1);
	}
	free_split(args);
	// while (1);
	return (g_sh);
}
