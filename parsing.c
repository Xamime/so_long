/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:30:30 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:27:06 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_player(t_vars *mapi, t_game nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	nb.player = 0;
	while (mapi->map[i])
	{
		j = 0;
		while (mapi->map[i][j])
		{
			if (mapi->map[i][j] == 'P')
				nb.player += 1;
			j++;
		}
		i++;
	}
	if (nb.player != 1)
		ft_error(5, mapi);
}

void	parse(t_vars mapi, int lastline)
{
	int	i;
	int	j;
	int	last;

	last = ft_strlen(mapi.map[0]) - 2;
	i = 0;
	while (mapi.map[i])
	{
		j = 0;
		while (mapi.map[i][j] != '\n' && mapi.map[i][j])
		{
			if (mapi.map[0][j] != '1' || mapi.map[lastline - 1][j] != '1')
				ft_error(1, &mapi);
			if (mapi.map[i][j] != '0'
			&& mapi.map[i][j] != 'P'
			&& mapi.map[i][j] != 'E'
			&& mapi.map[i][j] != 'C'
			&& mapi.map[i][j] != '1')
				ft_error(1, &mapi);
			j++;
		}
		if (mapi.map[i][0] != '1' || mapi.map[i][last] != '1')
			ft_error(1, &mapi);
		i++;
	}
}

t_game	parse_item_and_exit(t_vars *mapi)
{
	int		i;
	int		j;
	t_game	nb;

	i = 0;
	nb.exit = 0;
	nb.item = 0;
	while (mapi->map[i])
	{
		j = 0;
		while (mapi->map[i][j])
		{
			if (mapi->map[i][j] == 'C')
				nb.item += 1;
			if (mapi->map[i][j] == 'E')
				nb.exit += 1;
			j++;
		}
		i++;
	}
	if (nb.exit != 1)
		ft_error(3, mapi);
	if (nb.item < 1)
		ft_error(4, mapi);
	return (nb);
}

void	path_finding(t_vars *n, t_game *nb, int y, int x)
{	
	if (n->mapcpy[y][x] == 'E')
		nb->exit = 1;
	if (n->mapcpy[y][x] == '0' || n->mapcpy[y][x] == 'C')
	{
		if (n->mapcpy[y][x] == 'C')
			nb->item -= 1;
		n->mapcpy[y][x] = 'V';
		path_finding(n, nb, y - 1, x);
		path_finding(n, nb, y + 1, x);
		path_finding(n, nb, y, x + 1);
		path_finding(n, nb, y, x - 1);
	}
}
