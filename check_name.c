#include "fractol.h"
void	initstruct(t_complex *comp, t_color *col, char *argv)
{
	comp->pix_x = -2.0;
	comp->pix_y = -2.0;
	comp->i_max = 50;
	comp->zoom = WINDOW_WIDTH / 4;
	if (ft_strch(argv, "Julia"))
	{
		comp->c_re = -0.8;
    	comp->c_im = 0.156;
	}
}

void    print_fractol(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int ft_strch(char *string, char *str_chr)
{
    int i;

    i = 0;
    while (string[i] != '\0')
    {
        if (str_chr[i] == string[i])
            i++;
        else
            return (0);
    }
    return (1);
}

void *ft_check(t_complex *comp, t_color *col, char *argv)
{
    comp->av = argv;
    if (ft_strch(argv, "Mandelbrot"))
    {
        mandel(comp, col);
    }
    else if (ft_strch(argv, "Julia"))
    {
        jul(comp, col);
    }
    else if (ft_strch(argv, "Tricon"))
    {
        tricon(comp, col);
    }
    else
    {
        print_fractol(NAME_FRACTALS);
        return (NULL);
    }
}