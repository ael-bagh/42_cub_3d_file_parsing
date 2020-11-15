/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:46:48 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/15 20:53:07 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     longuest_line(void)
{
    int i;
    int j;
    int max;

    i = 0;
    j = 0;
    max = 0;
        while(g_map_array[i])
        {
            while(g_map_array[i][j] != '\0')
                j++;
            i++;
            if (j > max)
                max = j;
            j = 0;
        }
        //printf("longuest line:%d\n", max);
        return (max);
}

int     array_height(void)
{
        int i;

        i = 0;
        while (g_map_array[i])
           i++; 
        return (i);
}    

char    **map_manager(void)
{
    char **map_array;
    int i;

    i = 0;

    map_array = (char**)malloc(sizeof(char*) * array_height());
    while (i < longuest_line())
    {
        map_array[i] = (char*)malloc(sizeof(char) * longuest_line());
        map_array[i] = g_map_array[i];
        i++;
    }
    freethenipples(map_array);
    return (map_array);
}
