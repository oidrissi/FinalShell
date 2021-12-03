/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:08:13 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/11/30 15:35:06 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *a)
{
	int	n;

	n = 0;
	while (a[n])
		n++;
	return (n);
}

int	main(void)
{
	char	pwd[256];

	write(1, getcwd(pwd, sizeof(pwd)), ft_strlen(pwd));
	write(1, "\n", 1);
	return (0);
}
