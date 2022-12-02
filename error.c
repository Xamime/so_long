/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:59:06 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:17:22 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(t_vars *mapi)
{
	int		i;

	i = 0;
	while (mapi->map[i])
	{
		free(mapi->map[i++]);
	}
	free(mapi->map);
	i = 0;
	while (mapi->mapcpy[i])
	{
		free(mapi->mapcpy[i++]);
	}
	free(mapi->mapcpy);
	i = 0;
	while (mapi->mapcpy2[i])
	{
		free(mapi->mapcpy2[i++]);
	}
	free(mapi->mapcpy2);
}

void	ft_error(int error, t_vars *mapi)
{
	if (error == 1)
		ft_printf("Error\nInvalid map\n");
	else if (error == 2)
		ft_printf("Error\nNo path\n");
	else if (error == 3)
		ft_printf("Error\nInvalid number of exit\n");
	else if (error == 4)
		ft_printf("Error\nNo enough item\n");
	else if (error == 5)
		ft_printf("Error\nToo much or not enough player\n");
	else if (error == 10)
		ft_printf("GG\n");
	free_array(mapi);
	exit(0);
}

void	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i - 1]
			&& str[i] == '.'
			&& str[i + 1] == 'b'
			&& str[i + 2] == 'e'
			&& str[i + 3] == 'r'
			&& !str[i + 4])
			return ;
		i++;
	}
	ft_printf("Error\nInvalid argument\n");
	exit(0);
}
