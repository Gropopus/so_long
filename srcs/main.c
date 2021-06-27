/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:55:10 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/27 19:06:32 by thsembel         ###   ########.fr       */
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
	ft_printf("p_x %d p_y %d\nnb_move = %d	coin = %d\n", game->p_posx, game->p_posy, game->nb_move, game->p_coin);
	ft_print_tab(game->map);
	return (1);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->res_y = 600;
	game->res_x = 800;
	game->win = mlx_new_window(game->mlx, game->res_x, game->res_y, "So_long");
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, key_released, game);
	mlx_hook(game->win, 33, 0, exit_game, game);
	mlx_loop_hook(game->mlx, play, game);
	mlx_loop(game->mlx);
}

/*int	load_assets(t_game *game)
{
	int *height;
	int *width;

	*width = 600 / game->raw;
	*height = 800 / game->col;
	if (!(game->p_img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm", width, height)))
		return (ft_error("Cannot load player texture\n"));
	return (1);
}*/

int	main(int ac, char **av)
{
	t_game	game;

	game.nb_move = 0;
	game.p_coin = 0;
	if (ac != 2)
		return (ft_error("usage: ./so_long <Map.ber>\n"));
	if (ft_parsing(av[1], &game) == 0)
	{
		ft_free_tab(game.map);
		return (0);
	}
	start_game(&game);
	return (0);
}
