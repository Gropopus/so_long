/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:12:19 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/05 13:14:20 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	anim_human(t_game *game, int i, int j)
{
	static int	img = 0;

	if (game->map[i][j] == 'C')
	{
		if (img < 50)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->text.img[9],
				j * 32, i * 32);
			img++;
		}
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, game->text.img[2],
				j * 32, i * 32);
			img++;
		}
		if (img > 100)
			img = 0;
	}
}

void	display_player(t_game *game, int i, int j)
{
	anim_human(game, i, j);
	if (game->map[game->p_posx][game->p_posy] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[6],
			game->p_posy * 32, game->p_posx * 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[0],
			game->p_posy * 32, game->p_posx * 32);
	if (game->right)
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[7],
			game->e_posy * 32, game->e_posx * 32);
	else if (!game->right)
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[8],
			game->e_posy * 32, game->e_posx * 32);
	display_digits(game, 0, 0);
}

void	anim_exit(t_game *game, int i, int j)
{
	static int	anim = 0;

	if (anim < 10)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->text.img[1], j * 32, i * 32);
		anim++;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->text.img[5], j * 32, i * 32);
		anim++;
	}
	if (anim > 20)
		anim = 0;
}

void	display_map(t_game *game)
{
	int				i;
	int				j;

	i = 0;
	while (i < game->col)
	{
		j = 0;
		while (j < game->raw)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->text.img[4],
					j * 32, i * 32);
			else if (game->map[i][j] == 'E')
				anim_exit(game, i, j);
			else if (game->map[i][j] != '1')
				mlx_put_image_to_window(game->mlx, game->win, game->text.img[3],
					j * 32, i * 32);
			display_player(game, i, j);
			j++;
		}
		i++;
	}
}
