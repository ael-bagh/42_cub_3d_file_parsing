/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:27:14 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/14 11:42:01 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readline(void)
{
	int		fd;
	char	*line;

	fd = open("map.cub", O_RDONLY);
	global_init();
	while (get_next_line(fd, &line))
	{
		if (!all_params())
		{
			if (*line != '\0')
				routing(line);
		}
		else
		{
			routing(line);
		}
		free(line);
	}
	free(line);
	return (0);
}

void	routing(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		get_re(line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		get_no(line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		get_so(line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		get_we(line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		get_ea(line);
	else if (line[0] == 'S' && line[1] == ' ')
		get_s(line);
	else if (line[0] == 'F' && line[1] == ' ')
		get_f(line);
	else if (line[0] == 'C' && line[1] == ' ')
		get_c(line);
	else if (all_params())
		readmap(line);
	else
	{
		ft_putstr("one or many parametres format is wrong or missing!\n");
		exit(0);
	}
}

int		main(void)
{
	int a;
	readline();
	manage_map();
	printf("%d\n%d\n", g_width, g_height);
	printf("%s\n%s\n%s\n%s\n%s\n", g_no, g_so, g_we, g_ea, g_s);
	printf("floor rgb:%d,%d,%d\n", g_fr, g_fg, g_fb);
	printf("ceiling rgb:%d,%d,%d\n", g_cr, g_cg, g_cb);
	// printf("%s\n", g_map);
	for(int i = 0; g_map_array[i]; i++)
		printf("%s\n", g_map_array[i]);
		scanf("%d", &a);
}
