/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:36:41 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:26:26 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			ret += 1;
		i++;
	}
	return (ret);
}

int	count_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	find_x_y(t_vars *mapi)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mapi->map[i])
	{
		j = 0;
		while (mapi->map[i][j])
		{
			if (mapi->map[i][j] == 'P')
			{
				mapi->coor.x = j;
				mapi->coor.y = i;
			}
			j++;
		}
		i++;
	}
}
