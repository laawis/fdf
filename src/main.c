/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:01 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/20 14:58:08 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>

#include "fdf.h"
#include "libft.h"

// gcc main.c -I minilibx_macos -L minilibx_macos -l mlx -framework OpenGL -framework AppKit

/*
- Vecteur (additionner, soustraire, multiplier / diviser)
- Produit vectorielle / Produit scalaire


- Matrice 3x3 et 4x4
- Algorithme de brensham (tracer des lignes)
*/

/*
void	line(t_data *data, t_vertex *vertex1, t_vertex *vertex2)
void	line(t_data *data, int x1, int y1, int x2, int y2)
{
	int	dx = (x2 - x1); (vertex2->x - vertex1->x)
	int	dy = (y2 - y1); (vertex2->y - vertex1->y)
	int	m = 2 * dy;
	int	error = dx;
	int	errorInc = 2 * dx;
	int	Xincr = 1;
	int	Yincr = 1;
	int	i = 0;

transformation float to int :
	float	m = (dy / dx);  // * 2 * dx = 2 * dy;
	float	error = 0.5;   //  * 2 * dx = 2 * dx * 1/2 = dx;
	float	errorInc = 1.0;//  * 2 * dx = 2 * dx * 1.0 = 2 * dx;

	if (x1 > x2)
		Xincr = -1;
	if (y1 > y2);
		Yincr = -1;
	if (dx > dy)
	{
			if (dx < 0)
				dx *= -1;
			while (i <= dx)
			{
				my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
				error -= m;
				if (error <= 0)
				{
					y1 += Yincr;
					error += errorInc;
				}
				x1 += Xincr;
				i++;
			}
	}
	if (dx < dy)
	{
			if (dy < 0)
				dx *= -1;
			while (i <= dy)
			{
				my_mlx_pixel_put(data, x1, y1, 0x00FFFFFF);
				error -= m;
				if (error <= 0)
				{
					x1 += Yincr;
					error += errorInc;
				}
				y1 += Xincr;
				i++;
			}

	}

}
*/
/*
ssize_t	get_width(char ***matrix_altitude)
{
	size_t	i;
	size_t	j;
	ssize_t	width;

	if (matrix_altitude == NULL)

	width = 0;
	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		j = 0;
		while(matrix_altitude[i][j] != NULL)
		{
			j++
		}
		if (j != width && i > 0)
			return (-1);
		width = j;
		i++;
	}
	return (width);
}

t_vertex	**alloc_vertex_matrix(ssize_t width, ssize_t height)
{
	t_vertex	**matrix;
	size_t		i;

	matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (y + 1));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (matrix[i] != NULL)
	{
		matrix[i] = (t_vertex *)malloc(sizeof(t_vertex) * (x + 1))
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

t_vertex	**fill_vertex_matrix(t_vertex **vertex_matrix, char ***string_matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (vertex_matrix[i] != NULL)
	{
		j = 0;
		while (vertex_matrix[i][j] != NULL)
		{
			vertex_matrix->w = ft_atoi(string_matrix[i][j])
			j++;
		}
		i++;
	}
	return (vertex_matrix);
}
*/

int	main(int argc, char **argv)
{
	// void		*mlx;
    // void		*mlx_win;
    // t_data		img;
	// t_vertex	vertex1;
	// t_vertex	vertex2;
	ssize_t		height;
	ssize_t		width;
	char		***string_matrix;
	t_vertex	**vertex_matrix;

	(void)argc;

	height = get_line_number(argv[1]);
	if (height < 0)
		return (-1);
	string_matrix = get_matrix_altitude(argv[1], height);
	print_matrix_altitude(string_matrix);
	width = get_width(string_matrix);
	if (width < 0)
		return (-1);
	vertex_matrix = alloc_vertex_matrix(width, height);
	if (vertex_matrix == NULL)
		return -1;
	fill_vertex_matrix(vertex_matrix, string_matrix);
	print_vertex_matrix(vertex_matrix, width, height);
	free_matrix_altitude(string_matrix);
	free_vertex_matrix(vertex_matrix, height);
	// mettre tout ca dans des belles fonctions qui donnent une t_map


	(void)string_matrix;
	(void)vertex_matrix;
	// init_vertex(&vertex1, 14, 1, 0, 0x00FFFFFF);
	// init_vertex(&vertex2, 9, 2, 0, )
	// mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fdf project");

    // img.img = mlx_new_image(mlx, WIDTH, HEIGHT);

    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
    // my_mlx_pixel_put(&img, 150, 400, 0x00FFFFFF);
	// // line(&img, 0, 500, 500, 200);

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // // 60 FPS => 60 images par seconde => 1000ms / 60 = 16ms pour créer une image
    // mlx_loop(mlx);
    return (0);
}

// 0 1 0
// 1 1 0

/*

tableau de char *
<=>
tableau de tableau de char
<=>
tableau de tableau de points (t_vertex)
<=>
matrice de points (t_vertex)

------

line0 = gnl(fd);

line0 -> "0 1 0 20\n\0"
		 "0 1 0 20\0\0"
len = ft_strlen(line0);
if (len > 0)
	line0[len - 1] = '\0';

line0 -> "0 1 0 20\0\0"

------


Chaque nombre sur la ligne

depart (char **lines) tableau de lignes

lines = [
	"0 1 0 20",
	"1 1 0 -3"
]

----

lines[0] = "0 1 0 20"
lines[1] = "0 1 0 -3"

ft_split(lines[0], ' ') -> ["0", "1", "0", "20"]
ft_split(lines[1], ' ') -> ["0", "1", "0", "-3"]

ensuite
MATRIX_ALTITUDE FINI
matrix_altitude = [
	["0", "1", "0", "20"],
	["0", "1", "0", "-3"],
]

type(matrix_altitude) -> char *** <=> string **

char ***get_matrix_altitude(int fd);

----

fin (t_vertex **matrix) matrice de points <=> tableau de tableaux de points
[
	[{0,0,0}, {1,0,1}, {2,0,0}]
	[{0,1,1}, {1,1,1}, {2,1,0}]
]

*/

