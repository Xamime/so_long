/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:33:43 by mdesrose          #+#    #+#             */
/*   Updated: 2022/12/02 18:33:07 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_sprites
{
	void	*wall;
	void	*player;
	void	*item;
	void	*exit;
	void	*back;
}				t_sprt;

typedef struct s_coordinates
{
	int		x;
	int		y;
}				t_coor;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_sprt	img;
	t_coor	coor;
	int		wid;
	int		hght;
	char	**map;
	char	**mapcpy;
	char	**mapcpy2;
	int		count;
	int		i;
	int		j;
}				t_vars;

typedef struct s_game
{
	int		player;
	int		item;
	int		itemsum;
	int		exit;
	t_coor	coor;
}				t_game;

/////////////////////////////////////////////////////
///												  ///
///					parsing						  ///
///												  ///
/////////////////////////////////////////////////////

void	path_finding(t_vars *n, t_game *nb, int y, int x);
t_game	parse_item_and_exit(t_vars *mapi);
void	parse(t_vars mapi, int lastline);
void	parse_player(t_vars *mapi, t_game nb);

/////////////////////////////////////////////////////
///												  ///
///					 utils.c					  ///
///												  ///
/////////////////////////////////////////////////////

int		count_array(char **str);
int		count_line(char *str);
void	find_x_y(t_vars *mapi);

/////////////////////////////////////////////////////
///												  ///
///					 error.c					  ///
///												  ///
/////////////////////////////////////////////////////

void	ft_error(int error, t_vars *mapi);	
void	free_array(t_vars *mapi);
void	check_ber(char *str);

/////////////////////////////////////////////////////
///												  ///
///					  init.c					  ///
///												  ///
/////////////////////////////////////////////////////

t_vars	init_array(char *str);
void	init_map(t_vars *vars);
void	init_sprites(t_vars *vars);

/////////////////////////////////////////////////////
///												  ///
///					  display.c					  ///
///												  ///
/////////////////////////////////////////////////////

void	all_hooks(t_vars *vars);
int		key_hook2(int keycode, t_vars *vars, t_game *nb);
int		key_hook3(int keycode, t_vars *vars, t_game *nb);
int		key_hook4(int keycode, t_vars *vars, t_game *nb);

/////////////////////////////////////////////////////
///												  ///
///					   move.c					  ///
///												  ///
/////////////////////////////////////////////////////

void	move_left(t_vars *vars, int *count, t_game *nb);
void	move_right(t_vars *vars, int *count, t_game *nb);
void	move_down(t_vars *vars, int *count, t_game *nb);
void	move_up(t_vars *vars, int *count, t_game *nb);
int		collect_item(t_vars *vars, t_game *nb);

/////////////////////////////////////////////////////
///												  ///
///					   main.c					  ///
///												  ///
/////////////////////////////////////////////////////

void	go_exit(t_vars *vars);
void	ft_end(t_vars *vars);

#endif