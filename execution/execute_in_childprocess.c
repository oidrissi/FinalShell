/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_in_childprocess.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:48:32 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/02 18:24:06 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	get_path_index(char **env)
{
	int	i;
	int	j;
	int	nbr_colons;

	i = -1;
	j = 4;
	nbr_colons = 1;
	while (env[++i])
	{
		if (ft_strlen(env[i]) >= 6 && env[i][0] == 'P' && env[i][1] == 'A'
			&& env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
		{
			while (env[i][++j])
			{
				if (env[i][j] != ':')
					nbr_colons = 0;
				else
					nbr_colons++;
				if (nbr_colons == 2 || (nbr_colons == 1 && env[i][++j] == '\0'))
					return (-1);
			}
			return (i);
		}
	}
	return (-1);
}

int	ft_stat(char *dir, char *nxt_dir, char **args, char **env)
{
	struct stat	stats;
	int			i;

	i = stat(dir, &stats);
	if (i == -1)
	{
		if (!nxt_dir)
		{
			printf("minishell: %s: command not found\n", args[0]);
			exit (127);
		}
		return (-1);
	}
	if (!S_ISDIR(stats.st_mode) && (stats.st_mode & S_IXUSR))
		last_step(dir, args, env);
	if (S_ISDIR(stats.st_mode))
	{
		printf("minishell: %s: command not found\n", args[0]);
		exit(127);
	}
	else if (!(stats.st_mode & S_IXUSR))
		printf("minishell: %s: Permission denied\n", dir);
	exit(126);
}

void	search_in_path_dir(char **args, char **env)
{
	char	**dir;
	int		i;
	char	*tmp;

	i = get_path_index(env);
	if (i == -1)
		return ;
	dir = ft_split(env[i] + 5, ':');
	i = -1;
	while (dir[++i])
	{
		tmp = dir[i];
		dir[i] = ft_strjoin(dir[i], "/");
		free(tmp);
		tmp = dir[i];
		dir[i] = ft_strjoin(dir[i], args[0]);
		free(tmp);
		ft_stat(dir[i], dir[i + 1], args, env);
	}
}

void	check_stats(int i, struct stat stats, char *cmd)
{
	if (errno == 13)
	{
		printf("minishell: %s: Permission denied\n", cmd);
		exit(126);
	}
	if (errno == 20)
	{
		printf("minishell: %s: Not a directory\n", cmd);
		exit(126);
	}
	if (errno == 2)
	{
		printf("minishell: %s: No such file or directory\n", cmd);
		exit(127);
	}
	if (i == 0 && S_ISDIR(stats.st_mode))
	{
		printf("minishell: %s: is a directory\n", cmd);
		exit(126);
	}
	if (i == 0 && !(stats.st_mode & S_IXUSR))
	{
		printf("minishell: %s: Permission denied\n", cmd);
		exit(126);
	}
}

void	execute(char **args, char **env)
{
	int			i;
	struct stat	stats;

	if (args[0] == NULL)
		exit (0);
	if (args[0][1] == '\0' && args[0][0] == '.' && !args[1])
	{
		printf("bash: .: filename argument required\n");
		printf(".: usage: . filename [arguments]\n");
		exit(2);
	}
	i = -1;
	while (args[0][++i])
		if (args[0][i] == '/')
			break ;
	if (args[0][i] != '/')
		search_in_path_dir(args, env);
	errno = 0;
	i = stat(args[0], &stats);
	check_stats(i, stats, args[0]);
	last_step(args[0], args, env);
}
