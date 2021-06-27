/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:48:12 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/27 20:45:38 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include "../mlx_lib/mlx_opengl.h"
#include <fcntl.h>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN   "\033[0;36m"
# define NC     "\033[0m"
# define KEY_A				0
# define KEY_D				2
# define KEY_S				1
# define KEY_W				13
# define KEY_EXIT_HOOK		53

typedef struct s_game
{
	char	**map;
	int		p_posx;
	int		p_posy;
	int		raw;
	int		col;
	int		res_x;
	int		res_y;
	int		nb_move;
	int		p_coin;
	int		nb_coin;
	int		key_up;
	int		key_down;
	int		key_right;
	int		key_left;
	int		key_esc;
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*e_img;
	void	*c_img;
	void	*f_img;
	void	*w_img;
}				t_game;

typedef struct s_check
{
	int		player;
	int		exit;
	int		coin;
}				t_check;

int		ft_error(char *str);
void	move_player(t_game *game);
/*
**		ft_parsing.c
 */
int		ft_parsing(char *arg, t_game *game);
/*
**		ft_parsing2.c
*/
int		check_info(t_game *game, t_check *check, int i, int j);
/*
**		key.c
*/
int		key_released(int keycode, t_game *game);
int		key_pressed(int keycode, t_game *game);
/*
**		move.c
*/
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
/*
**		exit.c
*/
int		esc_game(t_game *game);
int		exit_game(t_game *game);
# endif
