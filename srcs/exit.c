/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:09:26 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/27 17:24:53 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *game)
{
	ft_free_tab(game->map);
	mlx_destroy_window(game->mlx, game->win);
//	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	exit(0);
}

int		esc_game(t_game *game)
{
	exit_game(game);
	exit(0);
	return (1);
}

