/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:01:08 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/27 17:55:40 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_released(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_up = 0;
	else if (keycode == KEY_S)
		game->key_down = 0;
	else if (keycode == KEY_A)
		game->key_left = 0;
	else if (keycode == KEY_D)
		game->key_right = 0;
	else if (keycode == KEY_EXIT_HOOK)
		game->key_esc = 1;
	return (keycode);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_EXIT_HOOK)
		esc_game(game);
	else if (keycode == KEY_W)
	{
		game->key_up = 1;
		move_up(game);
	}
	else if (keycode == KEY_S)
	{
		game->key_down = 1;
		move_down(game);
	}
	else if (keycode == KEY_A)
	{
		game->key_left = 1;
		move_left(game);
	}
	else if (keycode == KEY_D)
	{
		game->key_right = 1;
		move_right(game);
	}
	return (keycode);
}

