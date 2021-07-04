/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:23:14 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/04 17:41:08 by thsembel         ###   ########.fr       */
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

char	**set_digits_path(void)
{
	char	*path;
	char	**s_path;

	path = ft_strdup("./text/0.xpm ");
	path = ft_strjoin(path, "./text/1.xpm ./text/2.xpm ./text/3.xpm ");
	path = ft_strjoin(path, "./text/4.xpm ./text/5.xpm ./text/6.xpm ");
	path = ft_strjoin(path, "./text/7.xpm ./text/8.xpm ./text/9.xpm");
	if (path == NULL)
		return (NULL);
	s_path = ft_split(path, ' ');
	if (s_path == NULL)
		return (NULL);
	free(path);
	return (s_path);
}

void	display_collect(t_game *game)
{
	int	i;

	mlx_put_image_to_window(game->mlx, game->win, game->text.img[10], 0,
		(game->col - 1) * 32);
	if (game->p_coin> 999)
		return ;
	i = ft_get_tens(game->p_coin);
	if (i == 1)
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->p_coin], 1 * 32, (game->col - 1 ) * 32);
	else if (i == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->p_coin / 10], 1 * 32, (game->col - 1) * 32);
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->p_coin % 10], 2 * 32, (game->col - 1) * 32);
	}
}

void	display_digits(t_game *game, int nb, int i)
{
	display_collect(game);
	if (game->nb_move > 999)
		return ;
	i = ft_get_tens(game->nb_move);
	if (i == 1)
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move], 0 * 32, 0);
	else if (i == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move / 10], 0 * 32, 0);
		mlx_put_image_to_window(game->mlx, game->win,
		game->text.digits[game->nb_move % 10], 1 * 32, 0);
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
	path = set_digits_path();
	if (path == NULL)
		return (ft_error("Allocation memory for texture failed\n"));
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
