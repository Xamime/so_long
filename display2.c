/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:09:59 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:22:58 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook3(int keycode, t_vars *vars, t_game *nb)
{
	if (keycode == 115 && vars->map[vars->coor.y + 1][vars->coor.x] != '1')
	{
		if (vars->map[vars->coor.y + 1][vars->coor.x] == 'E'
		&& collect_item(vars, nb) == nb->item)
			go_exit(vars);
		else if (vars->map[vars->coor.y + 1][vars->coor.x] != 'E')
		{
			vars->coor.y++;
			move_down(vars, &vars->count, nb);
		}
	}
	return (0);
}

int	key_hook4(int keycode, t_vars *vars, t_game *nb)
{
	if (keycode == 119 && vars->map[vars->coor.y - 1][vars->coor.x] != '1')
	{
		if (vars->map[vars->coor.y - 1][vars->coor.x] == 'E'
		&& collect_item(vars, nb) == nb->item)
			go_exit(vars);
		else if (vars->map[vars->coor.y - 1][vars->coor.x] != 'E')
		{
			vars->coor.y--;
			move_up(vars, &vars->count, nb);
		}
	}
	return (0);
}
