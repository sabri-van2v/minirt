/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:46:46 by stde-la-          #+#    #+#             */
/*   Updated: 2023/09/11 12:55:43 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define LOADING_SYMBOLS "\\|/-"

void	loader(int frequency, int reset)
{
	static int	i = 0;
	static int	j = 0;

	if (reset == 1)
	{
		i = 0;
		j = 0;
		return ;
	}
	if (i % frequency == 0)
	{
		if (j != 0)
			write(1, "\b\b\b", 3);
		write(1, "[", 1);
		write(1, &(LOADING_SYMBOLS[j % 4]), 1);
		write(1, "]", 1);
		j++;
	}
	i++;
}

void	loading_bar(int max, float curr)
{
	int		i;
	float	progress;

	progress = curr / max * 50;
	i = 0;
	write(1, "\33[2K\r", 6);
	write(1, "[", 1);
	i = 1;
	while (i < progress)
	{
		write(1, "#", 1);
		i++;
	}
	while (i < 50)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "] ", 2);
	ft_putnbr_fd(curr / max * 100.0f, 1);
	write(1, "% ", 2);
	write(1, "[frame: ", 9);
	ft_putnbr_fd(curr, 1);
	write(1, "]", 2);
}
