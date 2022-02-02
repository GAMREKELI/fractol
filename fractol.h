/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:48:16 by pdursley          #+#    #+#             */
/*   Updated: 2022/02/02 16:48:18 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "./minilibx-linux/mlx.h"

# define WINDOW_NAME "test"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define COLOR_1 0x099B0E6
# define COLOR_2 0x041BECA
# define COLOR_3 0x0BE91D3
# define NAME_FRACTALS "-> Mandelbrot\n-> Julia\n-> Tricon\n"

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		length;
	int		end;
}				t_image;

typedef struct s_complex
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			z_re;
	double			z_im;
	double			z_re_pow;
	double			z_im_pow;
	double			c_re;
	double			c_im;
	int				iteration;
	double			re;
	double			im;
	int				i_max;
	double			pix_x;
	double			pix_y;
	int				x;
	int				y;
	double			zoom;
	unsigned int	color;
	char			*av;
	double			color_hex;
	int				flag;
	int				stop_jul;
	t_image			*ima;
}				t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

int		mandelbrot_mth(t_complex *comp);
void	mandel(t_complex *comp, t_color *col);
void	pixel(t_complex *comp, int x, int y, int color);
double	ft_color(t_complex *comp, t_color *col);
double	draw(t_complex *comp, t_color *col, double smooth);
void	ft_check(t_complex *comp, t_color *col, char *argv);
void	jul(t_complex *comp, t_color *col);
void	tricon(t_complex *comp, t_color *col);
void	burning(t_complex *comp, t_color *col);
int		ft_strch(char *string, char *str_chr);
void	initstruct(t_complex *comp, char *argv);
int		mouse_hook(int button, int x, int y, t_complex *comp);
int		motion_julia(int x, int y, t_complex *comp);
int		keycode(int keypress, t_complex *comp);
int		ft_close(int keypress, t_complex *comp);
void	print_fractol(char *s);

#endif
