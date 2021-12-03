/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 09:11:02 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 18:10:06 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	get_the_new_hdoc_pipe_toread_from(char *when_to_stop, int *fd)
{
	char	*readline_return;
	int		pipe_fd[2];

	pipe(pipe_fd);
	readline_return = NULL;
	while (1)
	{
		if (readline_return)
			free(readline_return);
		readline_return = readline(">");
		if (ft_str_compare(readline_return, when_to_stop))
		{
			if (readline_return)
				free(readline_return);
			close(pipe_fd[1]);
			break ;
		}
		write(pipe_fd[1], readline_return, ft_strlen(readline_return));
		write(pipe_fd[1], "\n", 1);
	}
	*fd = pipe_fd[0];
	errno = 0;
}

void	heredoc(t_red *red, t_hdoc *hdoc)
{
	int	i;

	i = -1;
	hdoc->index = -1;
	hdoc->heredoc_pipe_input_fd = 0;
	while (++i >= 0)
	{
		if (red->type == 4)
		{
			hdoc->index = i;
			if (hdoc->heredoc_pipe_input_fd)
				close(hdoc->heredoc_pipe_input_fd);
			get_the_new_hdoc_pipe_toread_from(red->file,
				&hdoc->heredoc_pipe_input_fd);
		}
		if (red->next == NULL)
			break ;
		red = red->next;
	}
}
