/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:40:10 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/13 18:06:04 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_re(char *line)
{
	char	**par;
	int		cw;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_width != 0 && g_height != 0)
	{
		ft_putstr("Error\ndouble inclusion\n");
		exit(0);
	}
	if (cw != 3)
	{
		ft_putstr("Error:\nwrong number of parameters in resolution!\n");
		exit(0);
	}
	if (str_is_digits(&par[1][0]) || str_is_digits(&par[2][0]))
		wrong_resolution(atoi(&par[1][0]), atoi(&par[2][0]));
	else
		ft_putstr("wrong resolution  zine !");
	freethenipples(par);
}

void	get_no(char *line)
{
	char	**par;
	int		cw;
	int		re;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_no != NULL)
	{
		ft_putstr("Error\ndouble inclusion\n");
		exit(0);
	}
	if (cw != 2)
	{
		ft_putstr("Error:\nWrong number of parametres in north texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) < 0))
	{
		ft_putstr("Error:\nFile or directory not found for north texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) > 0))
		g_no = ft_strdup(&par[1][0]);
	freethenipples(par);
}

void	get_so(char *line)
{
	char	**par;
	int		cw;
	int		re;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_so != NULL)
	{
		ft_putstr("Error\ndouble includion\n");
		exit(0);
	}
	if (cw != 2)
	{
		ft_putstr("Error:\nWrong number of parametres in south texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) < 0))
	{
		ft_putstr("Error:\nFile or directory not found for south texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) > 0))
		g_so = ft_strdup(&par[1][0]);
	freethenipples(par);
}

void	get_we(char *line)
{
	char	**par;
	int		cw;
	int		re;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_we != NULL)
	{
		ft_putstr("Error\ndouble includion\n");
		exit(0);
	}
	if (cw != 2)
	{
		ft_putstr("Error:\nWrong number of parametres in west texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) < 0))
	{
		ft_putstr("Error:\nFile or directory not found for west texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) > 0))
		g_we = ft_strdup(&par[1][0]);
	freethenipples(par);
}

void	get_ea(char *line)
{
	char	**par;
	int		cw;
	int		re;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_ea != NULL)
	{
		ft_putstr("Error\ndouble includion\n");
		exit(0);
	}
	if (cw != 2)
	{
		ft_putstr("Error:\nWrong number of parametres in east texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) < 0))
	{
		ft_putstr("Error:\nFile or directory not found for east texture!\n");
		exit(0);
	}
	else if ((re = open(&par[1][0], O_RDONLY) > 0))
		g_ea = ft_strdup(&par[1][0]);
	freethenipples(par);
}
