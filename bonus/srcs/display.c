/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:12:19 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/03 22:02:24 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_pc(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[2],
			j * 32, i * 32);
	}
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
	display_digits(game, 0);
}

void	draw_map(t_game *game, int anim)
{
	int		i;
	int		j;

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
			{
				if (anim % 5 == 0)
					mlx_put_image_to_window(game->mlx, game->win,
					game->text.img[1], j * 32, i * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win,
					game->text.img[5], j * 32, i * 32);
			}
			else if (game->map[i][j] != '1')
				mlx_put_image_to_window(game->mlx, game->win, game->text.img[3],
					j * 32, i * 32);
			display_pc(game, i, j);
			j++;
		}
		i++;
	}
}

void	display_map(t_game *game)
{
	static int anim;

	draw_map(game, anim);
	if (anim == 2147483647)
		anim = 0;
	anim++;
}
