/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 00:37:44 by thsembel          #+#    #+#             */
/*   Updated: 2021/06/30 16:34:46 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_char_ok(char c)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
		return (-1);
	return (1);
}

int	is_info_ok(t_check *check, t_game *game)
{
	if (check->player != 1)
		return (ft_error("Player must have a single start position\n"));
	if (check->coin == 0)
		return (ft_error("Map must contain at least one object\n"));
	if (check->exit == 0)
		return (ft_error("Map must have at least one exit\n"));
	game->nb_coin = check->coin;
	return (1);
}

int	check_info(t_game *game, t_check *check, int i, int j)
{
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_posx = i;
				game->p_posy = j;
				game->map[i][j] = '0';
				check->player++;
			}
			else if (game->map[i][j] == 'C')
				check->coin++;
			else if (game->map[i][j] == 'E')
				check->exit++;
			else if (is_char_ok(game->map[i][j]) == -1)
				return (ft_error("Invalid character in map\n"));
			j++;
		}
		i++;
	}
	if (is_info_ok(check, game) == 0)
		return (0);
	return (1);
}
