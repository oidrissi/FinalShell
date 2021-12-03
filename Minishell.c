/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:52:22 by oidrissi          #+#    #+#             */
/*   Updated: 2021/11/27 02:52:03 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_g_sh_args()
{
	t_cmd *cmd;
	int i;
	
	cmd = g_sh;
	while(cmd)
	{
		i  = -1;
		while(cmd->args[++i])
	 		free(cmd->args[i]);
		free(cmd->args);
		cmd = cmd->next;
	}
}

void	free_g_sh()
{
	t_cmd *tmp;
	t_red *tmp2;
	
	tmp = g_sh;
	while(tmp)
	{
		// tmp2 = tmp->red;
		// while(tmp2)
		// {
		// 	tmp2 = tmp2->next;
		// 	free(tmp2);
		// }
		free_g_sh_args();
		tmp = tmp->next;
		free(tmp);
	}
}

void	boucle(char *line, char **env, int exit_status)
{
	change_env_to_heap(&env, 0, 0, -1);
	while (1)
	{
		line = readline("Sh> ");
		if (line == NULL)
		{
			write(1, "exit\n", 5);
			exit(1);
		}
		if (*line)
			add_history(line);
		line = trim_whitespaces(line);
		if (!parse(line))
		{
			write(1, "syntax error\n", 13);
			continue;
		}
		else if (parse(line) == 2)
			continue ;
		if (line == NULL || !*line)
				continue ;
		g_sh = fill_sh(line, exit_status, env);
		execute_command(g_sh, &exit_status, &env);
		// free(line);
		// free_g_sh();
		free(g_sh);
		g_sh =NULL;
		// while (1);
	}
}

int main(int ac, char **av, char **env)
{
    char	*line;
	int 	exit_status;

	exit_status = 0;
	(void)av;
	if (ac != 1)
		return (0);
	ignctl();
	signal(SIGINT, handlesig);
	signal(SIGQUIT, SIG_IGN);
	boucle(line, env, exit_status);
	free(line);
	return (0);
}