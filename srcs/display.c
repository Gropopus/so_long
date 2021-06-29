/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:12:19 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/29 15:18:14 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	mlx_get_pixel(void *img, int x, int y)
{
	return (*(unsigned int *)
		(img + (x * 3 / 8 + y * 32)));
}

void	mlx_draw_pixel(void *img, int x, int y, int color)
{
	char			*target;

	target = img + (x * 3 / 8 + y * 32);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

static void	draw_tile(void *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

/*static void	draw_env(t_root *root, int i, int j)
{
	int				k;

	if (root->game->exit.x == i && root->game->exit.y == j)
		draw_square(root, root->exit, i * 40, j * 40);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			draw_square(root, root->coll, i * 40, j * 40);
	if (root->game->player.x == i && root->game->player.y == j)
		draw_square(root, root->player, i * 40, j * 40);
}*/

static void	draw_map(t_game *game)
{
	int				i;
	int				j;

	j = 0;
	while (j < game->res_y)
	{
		i = 0;
		while (i < game->res_x)
		{
			if (game->map[j][i] == 1)
				draw_tile(game->text.img[4], i * 32, j * 32);
			else
				draw_tile(game->text.img[3], i * 32, j * 32);
		//	draw_env(game, i, j);
			i++;
		}
		j++;
	}
}

void	display_map(t_game *game)
{
	game->text.map_img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	draw_map(game);

	mlx_put_image_to_window(game->mlx, game->win, game->text.img, 0, 0);
}
