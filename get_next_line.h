/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:17:29 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/11/13 17:35:23 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define BUFFER_SIZE 10000

int		g_width;
int		g_height;
char	*g_no;
char	*g_so;
char	*g_we;
char	*g_ea;
char	*g_s;
char	*g_map;
char    **g_map_array;
int		g_fr;
int		g_fg;
int		g_fb;
int		g_cr;
int		g_cg;
int		g_cb;
int     map_started;
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*has_nl(char *str);
int		pre_work(int fd, char **rest, char **line);
char	**ft_split(char *str, char c);
int		c_w(char *str, char c);
void	get_re(char *line);
void	get_no(char *line);
void	get_we(char *line);
void	get_ea(char *line);
void	get_so(char *line);
void	get_s(char *line);
void	get_f(char *line);
void	get_c(char *line);
void	routing(char *line);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_words_tables(char **tab);
char	**freethenipples(char **s);
int		s_p(char *s, char c);
int		len_str(char *s, int i, char c);
int		ft_isdigit(int c);
int		array_is_rgb(char **colors);
int		str_is_digits(char *c);
void	global_init(void);
int		all_params(void);
void	readmap(char *line);
void	manage_map(void);
char	*ft_strjoi(char *s1, char *s2);
int		begins_by_nl(char **maptab);
void	mapcheck(char **maptab);
int		wrong_resolution(int width, int height);
void	get_resolution(int width, int height);
void	check_crgb(char **colors, int cc, int cw);
void	check_frgb(char **colors, int cc, int cw);
void	get_crgb(int r, int g, int b);
void	get_frgb(int r, int g, int b);

#endif
