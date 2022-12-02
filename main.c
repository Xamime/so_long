/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:51:44 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:25:08 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.back);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.item);
	mlx_destroy_image(vars->mlx, vars->img.player);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_array(vars);
	exit(0);
}

void	go_exit(t_vars *vars)
{
	ft_printf("GG\n");
	ft_end(vars);
}

static void	go_graphic(t_vars *var)
{
	var->wid = 60 * (ft_strlen(var->map[0]) - 1);
	var->hght = 60 * (count_array(var->map));
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->wid, var->hght, "So_long");
	init_sprites(var);
	all_hooks(var);
	mlx_loop(var->mlx);
	ft_end(var);
}

int	main(int ac, char **av)
{
	t_vars	mapi;
	t_game	nb;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		return (0);
	}
	check_ber(av[1]);
	mapi = init_array(av[1]);
	if (!mapi.map)
		return (0);
	nb = parse_item_and_exit(&mapi);
	parse_player(&mapi, nb);
	find_x_y(&mapi);
	nb.exit = 0;
	mapi.mapcpy[mapi.coor.y][mapi.coor.x] = '0';
	path_finding(&mapi, &nb, mapi.coor.y, mapi.coor.x);
	if (nb.item != 0)
		ft_error(2, &mapi);
	if (nb.exit != 1)
		ft_error(3, &mapi);
	go_graphic(&mapi);
	free_array(&mapi);
}
