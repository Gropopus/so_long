/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 21:55:10 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/05 15:33:01 by thsembel         ###   ########.fr       */
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
	ft_printf("%sAbductions:%s	%d\n\n", YELLOW, NC, game->p_coin);
	display_map(game);
	return (1);
}

void	start_game(t_game *game)
{
	game->res_y = (int)(game->col * game->text.y[4]);
	game->res_x = (int)(game->raw * game->text.x[4]);
	game->win = mlx_new_window(game->mlx, game->res_x, game->res_y, "So_long");
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 33, 1L << 5, esc_game, game);
	mlx_loop_hook(game->mlx, play, game);
	mlx_loop(game->mlx);
}

int	load_assets(t_game *game, int i, char *path, char **s_path)
{
	path = ft_strdup("./text/p.xpm ");
	path = ft_strjoinfree(path, "./text/e.xpm ./text/c.xpm ./text/f.xpm .", 0);
	path = ft_strjoinfree(path, "/text/w.xpm ./text/e2.xpm ./text/ep.xpm .", 0);
	path = ft_strjoinfree(path, "/text/tr.xpm ./text/tl.xpm ./text/c2.xpm ", 0);
	path = ft_strjoinfree(path, "./text/s.xpm", 0);
	if (path == NULL)
		return (ft_error("Failed to allocate memory for textures\n"));
	s_path = ft_split(path, ' ');
	free(path);
	if (s_path == NULL)
		return (ft_error("Failed to allocate memory for textures\n"));
	i = 0;
	while (i < 11)
	{
		game->text.img[i] = mlx_xpm_file_to_image(game->mlx, s_path[i],
				&game->text.x[i], &game->text.y[i]);
		if (!game->text.img[i])
		{
			ft_free_tab(s_path);
			return (ft_error("Cannot load map textures\n"));
		}
		i++;
	}
	ft_free_tab(s_path);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.nb_move = 0;
	game.p_coin = 0;
	game.right = 1;
	if (ac != 2)
		return (ft_error("usage: ./so_long <Map.ber>\n"));
	if (ft_parsing(av[1], &game) == 0)
	{
		ft_free_tab(game.map);
		return (0);
	}
	game.mlx = mlx_init();
	if (load_assets(&game, 0, NULL, NULL) == 0)
		return (exit_game(&game));
	if (ft_load_bonus(&game) == 0)
		return (0);
	start_game(&game);
	return (0);
}
