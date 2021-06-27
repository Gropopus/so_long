/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:37:04 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/27 18:54:42 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void		my_mlx_pixel_put(t_game *game, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = game->wall.addr + (y * game->world.res_x + x);
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

static void	draw_square(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_root *root, int i, int j)
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
}

static void	draw_map(t_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
				draw_square(root, root->wall, i * 40, j * 40);
			else
				draw_square(root, root->ground, i * 40, j * 40);
			draw_env(root, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_root *root)
{
	draw_map(root);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
}
