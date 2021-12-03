/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:57:05 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 15:34:44 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_write(int i, int n, char **argv)
{
	while (n-- > 0)
	{
		printf("%s", argv[i++]);
		if (n != 0)
			printf(" ");
	}
}

int	checkfor_n(char *p)
{
	int	i;

	i = 1;
	if (p[0] == '-' && p[1] == 'n')
	{
		while (p[++i] != '\0')
			if (p[i] != 'n')
				return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc > 1 && !checkfor_n(argv[1])))
	{
		ft_write(1, argc - 1, argv);
		printf("\n");
	}
	else
		ft_write(2, argc - 2, argv);
}
