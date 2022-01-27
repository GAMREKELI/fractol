#include "fractol.h"
int ft_close(int keypress, t_complex *comp)
{
	if (keypress == 48)  //65307
	{
		mlx_destroy_image (comp->mlx_ptr, comp->ima->img);
		exit(0);
		return (0);
	}
}

int	keycode(int keypress, t_complex *comp, t_color *col)
{
	int i;

    i = 0;
	if (keypress == 49)
        comp->color_hex = COLOR_1;
    if (keypress == 50)
        comp->color_hex = COLOR_2;
	if (keypress == 51)
        comp->color_hex = COLOR_3;
	if (keypress == 52)
        comp->color_hex = COLOR_4;
	if (keypress == 53)
        comp->color_hex = 0;    
	if (keypress == 65363)
		comp->pix_x += (comp->i_max / comp->zoom); // 39 (right)
	if (keypress == 65361)
		comp->pix_x -= (comp->i_max / comp->zoom); // 37 (left)
	if (keypress == 65364)
		comp->pix_y += (comp->i_max / comp->zoom); // 38 (up)
	if (keypress == 65362)
		comp->pix_y -= (comp->i_max / comp->zoom); // 40 (down)	   
	ft_check(comp, col, comp->av);
	return(0);
}

int	mouse_hook(int button, int x, int y, t_complex *comp)
{
	t_color col;

	if (button == 4)
	{
		comp->pix_x = (x / comp->zoom + comp->pix_x) - (x / (comp->zoom * 1.4));
		comp->pix_y = (y / comp->zoom + comp->pix_y) - (y / (comp->zoom * 1.4));
		comp->zoom *= 1.4;
		comp->i_max += 1;
	}
	if (button == 5)
	{
		comp->pix_x = (x / comp->zoom + comp->pix_x) - (x / (comp->zoom / 1.4));
		comp->pix_y = (y / comp->zoom + comp->pix_y) - (y / (comp->zoom / 1.4));
		comp->zoom /= 1.4;
		comp->i_max -= 1;
	}
	ft_check(comp, &col, comp->av);
	return (0);
}

int motion_julia(int x, int y, t_complex *comp)
{
	t_color col;

	comp->c_re = 4 * ((double)x / WINDOW_WIDTH - 0.5);
	comp->c_im = 4 * ((double)(WINDOW_HEIGHT - y) / WINDOW_HEIGHT - 0.5);
	ft_check(comp, &col, comp->av);
	return (0);
}