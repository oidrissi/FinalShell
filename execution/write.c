/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bagh <zel-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:58:24 by zel-bagh          #+#    #+#             */
/*   Updated: 2021/12/01 22:55:44 by zel-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"Minishell.h"
#include <limits.h>

// void	handlesig(int sig)
// // {
// // 	if (sig == SIGINT)
// // 	{
// //         write(1, "\n>", 1);
// //         write(1, ">", 1);
// // 		//rl_on_new_line();
// // 		//rl_replace_line("", 0);
// // 		rl_redisplay();
// // 	}
// // }


int main()
{
	//signal(SIGINT, handlesig);
	int i = (int)45242448456646464;

	unsigned char a = (char)i;
	i = (int)a;
	printf("%d\n", i);
}
