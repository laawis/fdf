/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:01 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/07 15:42:18 by gaollier         ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

matrix_altitude ->
[
	["-1", "0", "12"],
	["23", "0", "1"],
	["0", "2", "42"]
]

type(matrix_altitude) -> char ***

matrix_vertex =
[
	[{0, 0, -1}, {1, 0, 0}, {2, 0, 12}],
	[{0, 1, 23}, {1, 1, 0}, {2, 1, 1}],
	[{0, 2, 0}, {1, 2, 2}, {2, 2, 42}]
]

type(matrix_vertex) -> t_vertex **

*/

char ***get_matrix_altitude(char *map, size_t nb_line)
{
	char	***matrix;
	char	*line;
	int		fd;
	size_t	i;

	matrix = (char ***)malloc(sizeof(char**) * nb_line);
	if (matrix == NULL)
		return (NULL);
	// mettre dans une fonction fill_matrix
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		matrix[i] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
		i++;
	}
	//
	return (matrix);
}

ssize_t	get_line_number(char *map)
{
	const int	fd = open(map, O_RDONLY);
	size_t		x;
	char		*line;

	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	x = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		x++;
	}
	if (close(fd) == -1)
		return (-1);
	return (x);
}

int	main(int argc, char **argv)
{
	// void		*mlx;
    // void		*mlx_win;
    // t_data		img;
	// t_vertex	vertex1;
	// t_vertex	vertex2;
	size_t	line_nbr;
	char	***matrix;

	line_nbr = get_line_number(argv[1]);
	matrix = get_matrix_altitude(argv[1], line_nbr);


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
