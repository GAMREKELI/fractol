#include "fractol.h"

double draw(t_complex *comp, t_color *col, double color)
{
	double t;

	t = 3 * color / comp->i_max;
	col->B = 255 * (pow(t, 3) + 1);
	col->G = 255 * (pow(t, 2) + 4);
	col->R = 255 * pow(t, 3) + 8;
	t = (col->R + col->G + col->B);
	return (t);

}

double ft_color(t_complex *comp, t_color *col)
{
    double	color;
	double	smooth;

	smooth = log(comp->z_re * comp->z_re + comp->z_im * comp->z_im) / 4;
	color = smooth;
	if (color < 0)
		color = 0;
	return (draw(comp, col, color));
}
