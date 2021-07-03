/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:40:16 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/03 22:05:11 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move(t_game *game)
{
	if (game->map[game->e_posx][game->e_posy + 1] == '0' && game->right)
		game->e_posy += 1;
	else if (game->map[game->e_posx][game->e_posy + 1] != '0' && game->right)
		game->right = 0;
	else if (game->map[game->e_posx][game->e_posy - 1] == '0' && !game->right)
		game->e_posy -= 1;
	else if (game->map[game->e_posx][game->e_posy - 1] != '0' && !game->right)
		game-> right = 1;
}

void	move_up(t_game *game)
{
	if (game->map[game->p_posx - 1][game->p_posy] == '1')
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
			game->nb_move += 1;
			ft_printf("%stotal moves:%s %d\n", GREEN, NC, game->nb_move);
			ft_printf("%sYou Won !%s\n", GREEN, NC);
			exit_game(game);
		}
	}
	enemy_move(game);
	if (game->p_posx - 1 == game->e_posx && game->p_posy == game->e_posy)
	{
		ft_printf("%s...Game Over...%s\n", RED, NC);
		exit_game(game);
	}
	game->p_posx -= 1;
	game->nb_move += 1;
}

void	move_down(t_game *game)
{
	if (game->map[game->p_posx + 1][game->p_posy] == '1')
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
			game->nb_move += 1;
			ft_printf("%stotal moves:%s %d\n", GREEN, NC, game->nb_move);
			ft_printf("%sYou Won !%s\n", GREEN, NC);
			exit_game(game);
		}
	}
	enemy_move(game);
	if (game->p_posx + 1 == game->e_posx && game->p_posy == game->e_posy)
	{
		ft_printf("%s...Game Over...%s\n", RED, NC);
		exit_game(game);
	}
	game->p_posx += 1;
	game->nb_move += 1;
}

void	move_right(t_game *game)
{
	if (game->map[game->p_posx][game->p_posy + 1] == '1')
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
			game->nb_move += 1;
			ft_printf("%stotal moves:%s %d\n", GREEN, NC, game->nb_move);
			ft_printf("%sYou Won !%s\n", GREEN, NC);
			exit_game(game);
		}
	}
	enemy_move(game);
	if (game->p_posx == game->e_posx && game->p_posy + 1 == game->e_posy)
	{
		ft_printf("%s...Game Over...%s\n", RED, NC);
		exit_game(game);
	}
	game->p_posy += 1;
	game->nb_move += 1;
}

void	move_left(t_game *game)
{
	if (game->map[game->p_posx][game->p_posy - 1] == '1')
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
			game->nb_move += 1;
			ft_printf("%stotal moves:%s %d\n", GREEN, NC, game->nb_move);
			ft_printf("%sYou Won !%s\n", GREEN, NC);
			exit_game(game);
		}
	}
	enemy_move(game);
	if (game->p_posx == game->e_posx && game->p_posy - 1== game->e_posy)
	{
		ft_printf("%s...Game Over...%s\n", RED, NC);
		exit_game(game);
	}
	game->p_posy -= 1;
	game->nb_move += 1;
}
