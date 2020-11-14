/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:57:24 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/13 17:31:25 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_is_digits(char *c)
{
	int i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int		array_is_rgb(char **colors)
{
	int i;

	i = 0;
	while (colors[i])
	{
		if (str_is_digits(colors[i]))
		{
			if (!(atoi(colors[i]) <= 255) || !(atoi(colors[i]) >= 0))
			{
				ft_putstr("Error\n Wrong colors parametres!");
				exit(0);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

void	get_s(char *line)
{
	char	**par;
	int		cw;
	int		re;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_s != NULL)
	{
		ft_putstr("Error\ndouble includion\n");
		exit(0);
	}
	if (cw != 2)
	{
		ft_putstr("Error:\nWrong number of parametres in sprite texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) < 0))
	{
		ft_putstr("Error:\nFile or directory not found for sprite texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) > 0))
		g_s = ft_strdup(&par[1][0]);
	freethenipples(par);
}

void	get_f(char *line)
{
	char	**par;
	char	**colors;
	int		cc;
	int		cw;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	cc = c_w(&par[1][0], ',');
	colors = ft_split(&par[1][0], ',');
	freethenipples(par);
	check_frgb(colors, cc, cw);
	freethenipples(colors);
}

void	get_c(char *line)
{
	char	**par;
	char	**colors;
	int		cc;
	int		cw;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	cc = c_w(&par[1][0], ',');
	colors = ft_split(&par[1][0], ',');
	freethenipples(par);
	check_crgb(colors, cc, cw);
	freethenipples(colors);
}
