/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:08:28 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/24 00:14:07 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	texture_error(int error)
{
	if (error == 0)
		ft_putstr("Error\ndouble inclusion\n");
	else if (error == 1)
		ft_putstr("Error:\nWrong number of params/invalid file in NO!\n");
	else if (error == 2)
		ft_putstr("Error:\nWrong number of params/invalid file in SO!\n");
	else if (error == 3)
		ft_putstr("Error:\nWrong number of params/invalid file in WE!\n");
	else if (error == 4)
		ft_putstr("Error:\nWrong number of params/invalid file in EA!\n");
	else if (error == 5)
		ft_putstr("Error:\nWrong number of params/invalid file in EA!\n");
	exit(0);
}

void	free_this_shit(char *str, char **s)
{
	free(str);
	freethenipples(s);
}
