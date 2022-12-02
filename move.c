/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:21:29 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:26:00 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_item(t_vars *vars, t_game *nb)
{
	static int	i;

	if (vars->mapcpy2[vars->coor.y][vars->coor.x] == 'C')
		i++;
	vars->mapcpy2[vars->coor.y][vars->coor.x] = '0';
	return (i);
}

void	move_left(t_vars *vars, int *count, t_game *nb)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.player, vars->coor.x * 60, vars->coor.y * 60);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.back, (vars->coor.x + 1) * 60, vars->coor.y * 60);
	if (vars->mapcpy2[vars->coor.y][vars->coor.x] == 'C')
		collect_item(vars, nb);
	(*count)++;
	ft_printf("%d\n", *count);
}

void	move_right(t_vars *vars, int *count, t_game *nb)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.player, vars->coor.x * 60, vars->coor.y * 60);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.back, (vars->coor.x - 1) * 60, vars->coor.y * 60);
	if (vars->mapcpy2[vars->coor.y][vars->coor.x] == 'C')
		collect_item(vars, nb);
	(*count)++;
	ft_printf("%d\n", *count);
}

void	move_down(t_vars *vars, int *count, t_game *nb)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.player, vars->coor.x * 60, vars->coor.y * 60);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.back, vars->coor.x * 60, (vars->coor.y - 1) * 60);
	if (vars->mapcpy2[vars->coor.y][vars->coor.x] == 'C')
		collect_item(vars, nb);
	(*count)++;
	ft_printf("%d\n", *count);
}

void	move_up(t_vars *vars, int *count, t_game *nb)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.player, vars->coor.x * 60, vars->coor.y * 60);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.back, vars->coor.x * 60, (vars->coor.y + 1) * 60);
	if (vars->mapcpy2[vars->coor.y][vars->coor.x] == 'C')
		collect_item(vars, nb);
	(*count)++;
	ft_printf("%d\n", *count);
}
