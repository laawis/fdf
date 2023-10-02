#include <mlx.h>
#include <stdio.h>

// gcc main.c -I minilibx_macos -L minilibx_macos -l mlx -framework OpenGL -framework AppKit

/*
- Vecteur (additionner, soustraire, multiplier / diviser)
- Produit vectorielle / Produit scalaire


- Matrice 3x3 et 4x4
- Algorithme de brensham (tracer des lignes)
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
void	line(t_data *data, int x1, int y1, int x2, int y2)
{
	int	dx = (x2 - x1);
	int	dy = (y2 - y1);
	int	m = 2 * dy;
	int	error = dx;
	int	errorInc = 2 * dx;

transformation float to int : 
	float	m = (dy / dx);  // * 2 * dx = 2 * dy;
	float	error = 0.5;   //  * 2 * dx = 2 * dx * 1/2 = dx;
	float	errorInc = 1.0;//  * 2 * dx = 2 * dx * 1.0 = 2 * dx;

	if (x1 < x2 && y1 < y2 && dx > dy)
	{
			while (x1 <= x2)
			{
				my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
				error -= m;
				if (error <= 0) // normalement on check si error >= à 0.5 quand error vaut 0. Donc on check si error >= 0 quand error vaut -0.5
				{
					y1++;
					error += errorInc;
				}
				x1++;
			}
	}
	if (x1 > x2 && y1 < y2 && dx > dy)
	{
			while (x1 >= x2)
			{
				my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
				error -= m;
				if (error <= 0) // normalement on check si error >= à 0.5 quand error vaut 0. Donc on check si error >= 0 quand error vaut -0.5
				{
					y1++;
					error += errorInc;
				}
				x1--;
			}

	}
	if (x1 < x2 && y1 > y2 && dx > dy)
	{
		while (x1 <= x2)
		{
			my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
			error -= m;
			if (error <= 0)
			{
				y1--;
				error += errorInc;
			}
			x1++;
		}
	}
	if (x1 > x2 && y1 > y2 && dx > dy)
	{
		while (x1 >= x2)
		{
			my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
			error += m;
			if (error <= 0)
			{ 
				y1--;
				error += errorInc;
			}
			x1--;
		}
	}
}
*/


int	main(void)
{
	void	*mlx;
    void    *mlx_win;
    t_data  img;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Fdf project");

    img.img = mlx_new_image(mlx, 500, 500);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
    my_mlx_pixel_put(&img, 150, 400, 0x00FFFFFF);
	// line(&img, 0, 500, 500, 200);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // 60 FPS => 60 images par seconde => 1000ms / 60 = 16ms pour créer une image
    mlx_loop(mlx);
    return (0);
}