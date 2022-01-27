#include "fractol.h"

void	pixel(t_complex *comp, int x, int y, int color)
{
	char	*dst;

	dst = comp->ima->addr + (y * comp->ima->line_length + x * (comp->ima->bpp / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char *argv[])
{
    t_complex comp;
	t_color col;
	t_image image;

	if (argc != 2)
		return (1);
	comp.ima = &image;
    comp.mlx_ptr = mlx_init();
    comp.win_ptr = mlx_new_window(comp.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    comp.ima->img = mlx_new_image(comp.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    comp.ima->addr = mlx_get_data_addr(comp.ima->img, &comp.ima->bpp, &comp.ima->line_length, &comp.ima->endian);
	initstruct(&comp, &col, argv[1]);
	if (!ft_check(&comp, &col, argv[1]))
		return (1);
    mlx_key_hook(comp.win_ptr, keycode, &comp);
	mlx_mouse_hook(comp.win_ptr, mouse_hook, &comp);
	if (ft_strch(argv[1], "Julia"))
	{
		mlx_hook(comp.win_ptr, 6, 1L << 6, motion_julia, &comp);
	}
	mlx_hook(comp.win_ptr, 2, 1L << 0, ft_close, &comp);
	mlx_loop(comp.mlx_ptr);
	return (0);
}



//--------------gcc -L ./minilibx-linux/ fractol.h main.c mandelbrot.c color.c check_name.c julia.c -l mlx -lXext -lX11 -lm