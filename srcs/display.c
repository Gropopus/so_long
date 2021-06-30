/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:12:19 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/30 15:48:51 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_pc(t_game *game, int i, int j)
{
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->text.img[2],
			j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win, game->text.img[0],
		game->p_posy * 32, game->p_posx * 32);
}

void	draw_map(t_game *game)
{
	int i;
	int j;

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
				mlx_put_image_to_window(game->mlx, game->win, game->text.img[1],
				j * 32, i * 32);
			}
			else if (game->map[i][j] != '1' /*&& game->map[i][j] != 'E'*/)
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
	draw_map(game);
}
