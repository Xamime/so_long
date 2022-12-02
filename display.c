/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:39:33 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:30:24 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_end(vars);
	return (0);
}

static int	ft_close2(t_vars *vars)
{
	ft_end(vars);
	return (0);
}

int	key_hook2(int keycode, t_vars *vars, t_game *nb)
{
	if (keycode == 100 && vars->map[vars->coor.y][vars->coor.x + 1] != '1')
	{
		if (vars->map[vars->coor.y][vars->coor.x + 1] == 'E'
		&& collect_item(vars, nb) == nb->item)
			go_exit(vars);
		else if (vars->map[vars->coor.y][vars->coor.x + 1] != 'E')
		{
			vars->coor.x++;
			move_right(vars, &vars->count, nb);
		}
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_game	nb;

	nb = parse_item_and_exit(vars);
	if (vars->count > 20000)
		vars->count = 0;
	if (keycode == 97 && vars->map[vars->coor.y][vars->coor.x - 1] != '1')
	{
		if (vars->map[vars->coor.y][vars->coor.x - 1] == 'E'
		&& collect_item(vars, &nb) == nb.item)
			go_exit(vars);
		else if (vars->map[vars->coor.y][vars->coor.x - 1] != 'E')
		{
			vars->coor.x--;
			move_left(vars, &vars->count, &nb);
		}
	}
	key_hook2(keycode, vars, &nb);
	key_hook3(keycode, vars, &nb);
	key_hook4(keycode, vars, &nb);
	return (0);
}

void	all_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, ft_close, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close2, vars);
	mlx_key_hook(vars->win, key_hook, vars);
}
