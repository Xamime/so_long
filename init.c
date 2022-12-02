/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:56:48 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:24:43 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_vars *vars)
{
	while (vars->map[vars->i])
	{
		vars->j = 0;
		while (vars->map[vars->i][vars->j])
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.back, vars->j * 60, vars->i * 60);
			if (vars->map[vars->i][vars->j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.wall, vars->j * 60, vars->i * 60);
			else if (vars->map[vars->i][vars->j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.player, vars->j * 60, vars->i * 60);
			}
			else if (vars->map[vars->i][vars->j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.exit, vars->j * 60, vars->i * 60);
			else if (vars->map[vars->i][vars->j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.item, vars->j * 60, vars->i * 60);
			vars->j++;
		}
		vars->i++;
	}
}

void	init_sprites(t_vars *vars)
{
	vars->img.back = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/back.xpm", &vars->wid, &vars->hght);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/wall.xpm", &vars->wid, &vars->hght);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/player.xpm", &vars->wid, &vars->hght);
	vars->img.item = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/item.xpm", &vars->wid, &vars->hght);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/exit.xpm", &vars->wid, &vars->hght);
	vars->i = 0;
	init_map(vars);
}

static void	init_array2(int nb, t_vars *mapi, char *str)
{
	int	i;
	int	fd;

	i = 0;
	mapi->i = 0;
	fd = open(str, O_RDONLY);
	mapi->map[0] = get_next_line(fd);
	while (mapi->i < nb - 1)
		mapi->map[++mapi->i] = get_next_line(fd);
	close(fd);
	mapi->mapcpy = ft_calloc(nb + 1, sizeof(char *));
	mapi->mapcpy2 = ft_calloc(nb + 1, sizeof(char *));
	if (!mapi->mapcpy || !mapi->mapcpy2)
		return ;
	while (mapi->map[i])
	{
		mapi->mapcpy[i] = ft_strdup(mapi->map[i]);
		i++;
	}
	i = 0;
	while (mapi->map[i])
	{
		mapi->mapcpy2[i] = ft_strdup(mapi->map[i]);
		i++;
	}
}

static int	init_array1(char *str, t_vars *mapi)
{
	int		i;
	int		fd;
	char	*buffer;
	int		rd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nNo map\n");
		exit(0);
	}
	buffer = ft_calloc(5000, sizeof(char));
	if (!buffer)
	{
		exit(0);
	}
	rd = read(fd, buffer, 5000);
	if (!buffer)
		exit(0);
	i = count_line(buffer);
	close(fd);
	free(buffer);
	return (i);
}

t_vars	init_array(char *str)
{
	t_vars	mapi;

	mapi.j = init_array1(str, &mapi);
	mapi.map = ft_calloc(mapi.j + 1, sizeof(char *));
	init_array2(mapi.j, &mapi, str);
	parse(mapi, mapi.j);
	return (mapi);
}
