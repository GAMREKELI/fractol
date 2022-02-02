/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:48:30 by pdursley          #+#    #+#             */
/*   Updated: 2022/02/02 16:48:32 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keypress, t_complex *comp)
{
	if (keypress == 53)
	{
		mlx_destroy_image (comp->mlx_ptr, comp->ima->img);
		exit(0);
		return (0);
	}
	return (0);
}

int	keycode(int keypress, t_complex *comp)
{
	t_color	col;

	if (keypress == 6)
		comp->stop_jul = 0;
	if (keypress == 7)
		comp->stop_jul = 1;
	if (keypress == 18)
		comp->color_hex = COLOR_1;
	if (keypress == 19)
		comp->color_hex = COLOR_2;
	if (keypress == 20)
		comp->color_hex = COLOR_3;
	if (keypress == 21)
		comp->color_hex = 0;
	if (keypress == 123)
		comp->pix_x += (comp->i_max / comp->zoom);
	if (keypress == 124)
		comp->pix_x -= (comp->i_max / comp->zoom);
	if (keypress == 126)
		comp->pix_y += (comp->i_max / comp->zoom);
	if (keypress == 125)
		comp->pix_y -= (comp->i_max / comp->zoom);
	ft_check(comp, &col, comp->av);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_complex *comp)
{
	t_color	col;

	if (button == 4)
	{
		comp->pix_x = (x / comp->zoom + comp->pix_x) - (x / (comp->zoom * 1.2));
		comp->pix_y = (y / comp->zoom + comp->pix_y) - (y / (comp->zoom * 1.2));
		comp->zoom *= 1.2;
		comp->i_max += 1;
	}
	if (button == 5)
	{
		comp->pix_x = (x / comp->zoom + comp->pix_x) - (x / (comp->zoom / 1.2));
		comp->pix_y = (y / comp->zoom + comp->pix_y) - (y / (comp->zoom / 1.2));
		comp->zoom /= 1.2;
		comp->i_max -= 1;
	}
	ft_check(comp, &col, comp->av);
	return (0);
}

int	motion_julia(int x, int y, t_complex *comp)
{
	t_color	col;

	if (comp->stop_jul == 1)
	{
		comp->c_re = 4 * ((double)x / WINDOW_WIDTH - 0.5);
		comp->c_im = 4 * ((double)(WINDOW_HEIGHT - y) / WINDOW_HEIGHT - 0.5);
		ft_check(comp, &col, comp->av);
	}	
	return (0);
}
