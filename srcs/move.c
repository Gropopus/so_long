/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:40:16 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/30 16:32:15 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if ((game->map[game->p_posx - 1][game->p_posy] == '1')
		|| (game->map[game->p_posx - 1][game->p_posy] == 'E'
		&& game->nb_coin != game->p_coin))
		return ;
	else if (game->map[game->p_posx - 1][game->p_posy] == 'C')
	{
		game->p_coin += 1;
		game->map[game->p_posx - 1][game->p_posy] = '0';
	}
	if (game->map[game->p_posx - 1][game->p_posy] == 'E')
	{
		if (game->nb_coin == game->p_coin)
		{
			ft_printf("%sYou Won !%s", GREEN, NC);
			exit_game(game);
		}
	}
	game->p_posx -= 1;
	game->nb_move += 1;
}

void	move_down(t_game *game)
{
	if ((game->map[game->p_posx + 1][game->p_posy] == '1')
		|| (game->map[game->p_posx + 1][game->p_posy] == 'E'
		&& game->nb_coin != game->p_coin))
		return ;
	else if (game->map[game->p_posx + 1][game->p_posy] == 'C')
	{
		game->p_coin += 1;
		game->map[game->p_posx + 1][game->p_posy] = '0';
	}
	if (game->map[game->p_posx + 1][game->p_posy] == 'E')
	{
		if (game->nb_coin == game->p_coin)
		{
			ft_printf("%sYou Won !%s", GREEN, NC);
			exit_game(game);
		}
	}
	game->p_posx += 1;
	game->nb_move += 1;
}

void	move_right(t_game *game)
{
	if ((game->map[game->p_posx][game->p_posy + 1] == '1')
		|| (game->map[game->p_posx][game->p_posy + 1] == 'E'
		&& game->nb_coin != game->p_coin))
		return ;
	else if (game->map[game->p_posx][game->p_posy + 1] == 'C')
	{
		game->p_coin += 1;
		game->map[game->p_posx][game->p_posy + 1] = '0';
	}
	if (game->map[game->p_posx][game->p_posy + 1] == 'E')
	{
		if (game->nb_coin == game->p_coin)
		{
			ft_printf("%sYou Won !%s", GREEN, NC);
			exit_game(game);
		}
	}
	game->p_posy += 1;
	game->nb_move += 1;
}

void	move_left(t_game *game)
{
	if ((game->map[game->p_posx][game->p_posy - 1] == '1')
		|| (game->map[game->p_posx][game->p_posy - 1] == 'E'
		&& game->nb_coin != game->p_coin))
		return ;
	else if (game->map[game->p_posx][game->p_posy - 1] == 'C')
	{
		game->p_coin += 1;
		game->map[game->p_posx][game->p_posy - 1] = '0';
	}
	if (game->map[game->p_posx][game->p_posy - 1] == 'E')
	{
		if (game->nb_coin == game->p_coin)
		{
			ft_printf("%sYou Won !%s", GREEN, NC);
			exit_game(game);
		}
	}
	game->p_posy -= 1;
	game->nb_move += 1;
}
