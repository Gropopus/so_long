/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:55:10 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/01 15:07:57 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(char *str)
{
	ft_printf("%sError:%s %s", RED, NC, str);
	return (0);
}

int	play(t_game *game)
{
	ft_printf("%sMoves:%s	%d\n", CYAN, NC, game->nb_move);
	ft_printf("%sCoins:%s	%d\n\n", YELLOW, NC, game->p_coin);
	display_map(game);
	return (1);
}

void	start_game(t_game *game)
{
	game->res_y = (int)(game->col * game->text.y[4]);
	game->res_x = (int)(game->raw * game->text.x[4]);
	game->win = mlx_new_window(game->mlx, game->res_x, game->res_y, "So_long");
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 33, 0L, exit_game, game);
	mlx_loop_hook(game->mlx, play, game);
	mlx_loop(game->mlx);
}

int	load_assets(t_game *game)
{
	int		i;
	char	**path;

	path = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		game->text.img[i] = mlx_xpm_file_to_image(game->mlx, path[i],
				&game->text.x[i], &game->text.y[i]);
		if (!game->text.img[i])
		{
			ft_free_tab(path);
			return (ft_error("Cannot load player texture\n"));
		}
		i++;
	}
	ft_free_tab(path);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.nb_move = 0;
	game.p_coin = 0;
	if (ac != 2)
		return (ft_error("usage: ./so_long <Map.ber>\n"));
	if (ft_parsing(av[1], &game) == 0)
	{
		if (game.map != NULL)
			ft_free_tab(game.map);
		return (0);
	}
	game.mlx = mlx_init();
	if (load_assets(&game) == 0)
		return (exit_game(&game));
	start_game(&game);
	return (0);
}
