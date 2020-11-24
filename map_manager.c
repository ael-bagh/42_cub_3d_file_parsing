/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:46:48 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/23 10:48:13 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		surrend_by_spaces(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < g_map_width + 2)
			j++;
		map[i][j] = '\0';
		i++;
		j = 0;
	}
	i = -1;
	while (map[++i])
		map[i][0] = ' ';
	i = -1;
	while (map[0][++i])
		map[0][i] = ' ';
	i = -1;
	while (map[g_map_height][++i])
		map[g_map_height + 1][i] = ' ';
	i = -1;
	while (map[++i])
		map[i][g_map_width + 1] = ' ';
}

void		fill_map(char **map)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	j = 1;
	x = 0;
	y = 0;
	while (x < g_map_height)
	{
		while (y < g_map_width)
		{
			if (y < ft_strlen(g_map_array[x]))
				map[i][j] = g_map_array[x][y];
			else
				map[i][j] = ' ';
			y++;
			j++;
		}
		i++;
		x++;
		j = 1;
		y = 0;
	}
}

void		longuest_line(void)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (g_map_array[i])
	{
		while (g_map_array[i][j] != '\0')
			j++;
		i++;
		if (j > max)
			max = j;
		j = 0;
	}
	g_map_width = max;
}

void		player_init(char c, int x, int y)
{
	if (player.x != -1 || player.y != -1)
	{
		ft_putstr("the map has more than one player\n");
		exit(0);
	}
	else
	{
		player.x = (x * 32) + 16;
		player.y = (y * 32) + 16;
		if (c == 'N')
			player.rotationAngle = M_PI / 2;
		else if (c == 'S')
			player.rotationAngle = M_PI / 2;
		else if (c == 'E')
			player.rotationAngle = M_PI / 2;
		else if (c == 'W')
			player.rotationAngle = M_PI / 2;
	}
}

void		array_height(void)
{
	int i;

	i = 0;
	while (g_map_array[i])
		i++;
	g_map_height = i;
}

char		**map_manager(void)
{
	char	**map_array;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map_array = (char**)malloc((g_map_height + 3) * sizeof(char*));
	while (i < g_map_height + 2)
	{
		map_array[i] = (char*)malloc((g_map_width + 3) * sizeof(char));
		i++;
	}
	map_array[i] = NULL;
	surrend_by_spaces(map_array);
	fill_map(map_array);
	map_errors(map_array);
	if (player.x == -1 || player.y == -1)
	{
		ft_putstr("Player or map missing\n");
		exit(0);
	}
	return (map_array);
}

void		map_errors(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i <= g_map_height)
	{
		while (++j <= g_map_width)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '2'
			&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'E'
			&& map[i][j] != 'S' && map[i][j] != ' ')
				error_redirect(0);
			else if (map[i][j] != ' ' && map[i][j] != '1')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' '
				|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					error_redirect(1);
				if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
					player_init(map[i][j], i - 1, j - 1);
			}
		}
		j = 1;
	}
}

void		error_redirect(int error)
{
	if (error == 0)
		ft_putstr("map has an unknown character\n");
	else if (error == 1)
		ft_putstr("the map isnt closed");
	exit(0);
}
