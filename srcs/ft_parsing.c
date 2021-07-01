/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 22:01:06 by thsembel          #+#    #+#             */
/*   Updated: 2021/07/01 15:07:49 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
		&& str[i + 3] == 'r')
		return (1);
	else
		return (0);
}

int	read_map(int fd, t_game *game)
{
	int		ret;
	char	buff[5000];

	ft_bzero(buff, 5000);
	while (1)
	{
		ret = read(fd, buff, 5000);
		if (ret < 0)
			return (ft_error("Map cannot be read\n"));
		if (ret == 0)
			break ;
	}
	game->map = ft_split(buff, '\n');
	if (game->map == NULL)
		return (ft_error("Failed to allocate memory for the Map\n"));
	return (1);
}

int	is_closed(t_game *game, int i, int end)
{
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	end = ft_strlen(game->map[0]) - 1;
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (ft_error("Map is not closed\n"));
		else if (game->map[i][end] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	i = 0;
	end = ft_tab_len(game->map) - 1;
	while (game->map[end][i])
	{
		if (game->map[end][i] != '1')
			return (ft_error("Map is not closed\n"));
		i++;
	}
	return (1);
}

int	is_rect(t_game *game)
{
	int	i;

	game->raw = ft_strlen(game->map[0]);
	game->col = ft_tab_len(game->map);
	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->raw)
			return (ft_error("Map is not a rectangle\n"));
		i++;
	}
	return (1);
}

int	ft_parsing(char *arg, t_game *game)
{
	int		fd;
	t_check	check;

	game->map = NULL;
	check.player = 0;
	check.exit = 0;
	check.coin = 0;
	if (is_ber(arg) == 0)
		return (ft_error("Map must end with .ber\n"));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (ft_error("Map cannot be openned\n"));
	if (read_map(fd, game) == 0)
		return (0);
	if (is_rect(game) == 0 || is_closed(game, 0, 0) == 0)
		return (0);
	if (check_info(game, &check, 0, 0) == 0)
		return (0);
	return (1);
}
