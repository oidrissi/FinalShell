/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:43:31 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 15:08:29 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minishell.h"

int	copy_old_env(char **new_env, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	free(env);
	return (i);
}

char	**add_oldpwd(char **env)
{
	char	**new_env;
	int		i;

	new_env = malloc((number(env) + 2) * sizeof(char *));
	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	new_env[i] = copy_string("OLDPWD");
	new_env[++i] = NULL;
	free(env);
	return (new_env);
}

char	**add_pwd(char **env)
{
	char	**new_env;
	int		i;
	char	pwd[256];

	new_env = malloc((number(env) + 2) * sizeof(char *));
	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	new_env[i] = ft_strjoin("PWD=", getcwd(pwd, sizeof(pwd)));
	new_env[++i] = NULL;
	free(env);
	return (new_env);
}

void	change_env_to_heap(char ***env, int pwd, int oldpwd, int i)
{
	char	**new_env;
	char	**p;
	char	pwwd[256];

	p = *env;
	new_env = malloc((number(p) + 1) * sizeof(char *));
	while (p[++i])
	{
		if (ft_compaire("OLDPWD", p[i]) == 2 && ++oldpwd)
			new_env[i] = copy_string("OLDPWD");
		else if (ft_compaire("PWD", p[i]) == 2 && ++pwd)
			new_env[i] = ft_strjoin("PWD=", getcwd(pwwd, sizeof(pwwd)));
		else
			new_env[i] = copy_string(p[i]);
	}
	new_env[i] = NULL;
	*env = new_env;
	if (!oldpwd)
		*env = add_oldpwd(*env);
	if (!pwd)
		*env = add_pwd(*env);
	add_shlvl(env);
}

int	number(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}
