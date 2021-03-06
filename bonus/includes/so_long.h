/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:48:12 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/05 13:46:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/ft_printf.h"
# include "../../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN   "\033[0;36m"
# define NC     "\033[0m"
/*		MAC
# define KEY_A				0
# define KEY_D				2
# define KEY_S				1
# define KEY_W				13
# define KEY_EXIT_HOOK		53*/
# define KEY_A				97
# define KEY_D				100
# define KEY_S				115
# define KEY_W				119
# define KEY_A				97
# define KEY_D				100
# define KEY_EXIT_HOOK			65307

# define PATH "./text/p.xpm ./text/e.xpm ./text/c.xpm ./text/f.xpm ./text/w.xpm"

typedef struct s_tex
{
	void		*img[11];
	void		*digits[10];
	int			x[9];
	int			y[9];
}				t_tex;

typedef struct s_game
{
	char	**map;
	int		right;
	int		e_posx;
	int		e_posy;
	int		p_posx;
	int		p_posy;
	int		raw;
	int		col;
	int		res_x;
	int		res_y;
	int		nb_move;
	int		p_coin;
	int		nb_coin;
	void	*mlx;
	void	*win;
	t_tex	text;

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
/*
**		display.c
*/
void	display_coin_player(t_game *game);
void	display_map(t_game *game);
/*
**		load_bonus.c
*/
int		ft_load_bonus(t_game *game);
void	display_digits(t_game *game, int nb, int i);

#endif
