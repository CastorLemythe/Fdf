/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:31:40 by lufranco          #+#    #+#             */
/*   Updated: 2018/03/12 18:00:12 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./../libft/libft.h"
# include "./../miniLibX/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_case
{
	void	*mlx;
	void	*win;
	void	*ptr_ima;
	char	*str_ima;
	int		**map;
	int		projection;
	int		iso;
	int		height;
	int		width;
	int		move_x;
	int		move_y;
	int		x;
	int		y;
	int		z_iso;
	int		z_para;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		h;
	int		w;
	int 		min;
	int		max;
	int		color;
	int 		alt;
	int		alt_to;
	int		x_ima;
	int		y_ima;
}				t_case;

int		my_key_funct(int keycode, t_case *stock);
char	**ft_parsing(char **dest, char *file, t_case *stock);
char	**ft_get_tab(char **dest, char *file, int fd, t_case *stock);
int		ft_check_char(char *dest);
int		ft_count(char **dest, t_case *stock);
int		ft_check_iso(int **map, int height ,int width);
int		**ft_tab_atoi(char **dest, int **map);
int     ft_my_atoi(char *tab, int *i);
void	ft_create_window(t_case *stock);
void	ft_choose_display(t_case *stock);
void	ft_display_iso(t_case *stock, int x, int y);
void	ft_display_para(t_case *stock, int x, int y);
void	z_para_iso(t_case *stock);
int	z_para_max(t_case *stock);
void	ft_mlx_loop(t_case *stock);
void	ft_draw_square(t_case *stock, int alt);
void	ft_print_commands(t_case *stock);
void	draw_hub(t_case *stock, int alt, int alt_to);
void	draw2(t_case *stock);
void	draw1(t_case *stock);
void	draw_v(t_case *stock);
void	pixel(int x, int y, double evo, t_case *stock);
void	color_hub(int alt, int alt_to, double evo, t_case *stock);
void	min_max(t_case *stock);
void	fill_pixel(t_case *stock, int x, int y, int color);
void	image(t_case *stock, int x, int y);
void	zoom(int key, t_case *stock);
#endif
