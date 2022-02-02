/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdursley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:47:14 by pdursley          #+#    #+#             */
/*   Updated: 2022/02/02 16:47:29 by pdursley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	draw(t_complex *comp, t_color *col, double color)
{
	double	t;

	t = 3 * color / comp->i_max;
	col->b = 255 * (pow(t, 3) + 1);
	col->g = 255 * (pow(t, 2) + 4);
	col->r = 255 * pow(t, 3) + 8;
	t = (col->r + col->g + col->b);
	return (t);
}

double	ft_color(t_complex *comp, t_color *col)
{
	double	color;
	double	smooth;

	smooth = log(comp->z_re * comp->z_re + comp->z_im * comp->z_im) / 4;
	color = smooth;
	if (color < 0)
		color = 0;
	return (draw(comp, col, color));
}
