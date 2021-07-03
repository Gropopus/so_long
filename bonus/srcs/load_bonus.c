/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:23:14 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/03 20:32:40 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	get_tens(int nb)
{
	int	nbr;
	int	i;

	nbr = nb;
	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	display_digits(t_game *game, int nb)
{
	int	i;

	if (game->nb_move > 999)
		return ;
	i = ft_get_tens(game->nb_move);
	if (i == 1)
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move], 2 * 32, 0);
	else if (i == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move / 10], 1 * 32, 0);
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move % 10], 2 * 32, 0);
	}
	else if (i == 3)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move / 100], 0, 0);
		nb = game->nb_move % 100;
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[nb / 10], 1 * 32, 0);
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move % 10], 2 * 32, 0);
	}
}

int	ft_load_bonus(t_game *game)
{
	char **path;
	int i;

	i = 0;
	path = ft_split("./text/0.xpm ./text/1.xpm ./text/2.xpm ./text/3.xpm ./text/4.xpm ./text/5.xpm ./text/6.xpm ./text/7.xpm ./text/8.xpm ./text/9.xpm", ' ');
	ft_print_tab(path);
	while (i < 10)
	{
		game->text.digits[i] = mlx_xpm_file_to_image(game->mlx, path[i],
				&game->text.x[i], &game->text.y[i]);
		if (!game->text.img[i])
		{
			ft_free_tab(path);
			return (ft_error("Cannot load bonus texture\n"));
		}
		i++;
	}
	ft_free_tab(path);
	return (1);
}
