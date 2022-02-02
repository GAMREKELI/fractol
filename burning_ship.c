#include "fractol.h"

int	burning_mth(t_complex *comp)
{
	int	iteration;

	iteration = 0;
	comp->z_re = 0;
	comp->z_im = 0;
	comp->z_re_pow = pow(comp->z_re, 2);
	comp->z_im_pow = pow(comp->z_im, 2);
	comp->c_re = comp->x / comp->zoom + comp->pix_x;
	comp->c_im = comp->y / comp->zoom + comp->pix_y;
	while ((comp->z_re * comp->z_re + comp->z_im * comp->z_im) <= 4
		&& iteration < comp->i_max)
	{
		comp->z_re_pow = comp->z_re * comp->z_re;
		comp->z_im_pow = comp->z_im * comp->z_im;
		comp->z_im = fabs(2 * comp->z_re * comp->z_im) + comp->c_im;
		comp->z_re = comp->z_re_pow - comp->z_im_pow + comp->c_re;
		iteration++;
	}
	return (iteration);
}

void	ft_draw_burn(t_complex *comp, t_color *col)
{
	comp->iteration = burning_mth(comp);
	if (comp->iteration == comp->i_max)
		comp->color = 0x080808;
	else
	{
		comp->color = ft_color(comp, col)
			* (double)comp->iteration + comp->color_hex;
	}
	pixel(comp, comp->x, comp->y, comp->color);
}

void	burning(t_complex *comp, t_color *col)
{
	comp->y = 0;
	while (comp->y < WINDOW_HEIGHT)
	{
		comp->x = 0;
		while (comp->x < WINDOW_WIDTH)
		{
			ft_draw_burn(comp, col);
			comp->x++;
		}
		comp->y++;
	}
	mlx_put_image_to_window(comp->mlx_ptr, comp->win_ptr, comp->ima->img, 0, 0);
}