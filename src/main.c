/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:01 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/12 14:39:25 by gaollier         ###   ########.fr       */
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
// STRING ARRAY =  TABLEAU DE TABLEAU = TABLEAU DE CHAINES DE CARACTERES.
/*


---- ft_split ----

string_array = malloc((n + 1) * sizeof(char *));

for (i < n)
{
	len = get_wordlen();
	string_array[i] = malloc((len + 1) * sizeof(char));
}
                         string_array[i]          string_array[i][j]
string_array --->   | string_array[0] -->	| 'l' (string_array[0][0])
					|						| 'o' (string_array[0][1])
					|						| 'l' (string_array[0][2])
					|						| '\0'
					|
					| string_array[1] -->	| 'n' (string_array[1][0])
					|						| 'o' (string_array[1][1])
					|						| 'n'
					|						| '\0'
					| ...
					| NULL

------------------

string_array = {
	{"Bonjour"},
	{"Monsieur"},
	{"Au revoir"},
	{NULL}
}
*/

void	free_strings(char **string_array)
{
	size_t	i;

	i = 0;
	while (string_array[i] != NULL)
	{
		free(string_array[i]);
		i++;
	}
}
void	free_matrix_altitude(char ***matrix_altitude)
{
	size_t	i;

	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		free_strings(matrix_altitude[i]);
		i++;
	}
	free(matrix_altitude);
}

static void	rm_newline(char *const line)
{
	const size_t	len = ft_strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

/*
	10 -1\n -> [10], [-1\n] -> [10], [-1]
	3 42\n -> [3], [42\n] -> [3], [42]
	1 4\n -> [1], [4\n] -> [1], [4]
*/

char	***fill_matrix(char ***matrix_altitude, const char *const filename)
{
	char	*line;
	int		fd;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		rm_newline(line);
		matrix_altitude[i] = ft_split(line, ' ');
		if (matrix_altitude[i] == NULL)
		{
			free_matrix_altitude(matrix_altitude);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (matrix_altitude);
}

void	print_matrix_altitude(char ***const matrix_altitude)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		j = 0;
		while (matrix_altitude[i][j] != NULL)
		{
			printf("[%s]", matrix_altitude[i][j]); // plus simple
			j++;
		}
		printf("\n");
		i++;
	}
}

char ***get_matrix_altitude(const char *const filename, const size_t nb_line)
{
	char	***matrix_altitude;
// Lorsque tu dereference 3fois un triple pointeur de char la variable devient un char

	matrix_altitude = (char ***)malloc(sizeof(char**) * (nb_line + 1));
	if (matrix_altitude == NULL)
		return (NULL);
	matrix_altitude = fill_matrix(matrix_altitude, filename);
	if (matrix_altitude == NULL)
		return (NULL);
	print_matrix_altitude(matrix_altitude);
	return (matrix_altitude);
}

ssize_t	get_line_number(char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	size_t		nb_line;
	char		*line;

	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	nb_line = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	if (close(fd) == -1)
		return (-1);
	return (nb_line);
}

int	main(int argc, char **argv)
{
	// void		*mlx;
    // void		*mlx_win;
    // t_data		img;
	// t_vertex	vertex1;
	// t_vertex	vertex2;
	ssize_t	line_nbr;
	char	***matrix;

	(void)argc;
	line_nbr = get_line_number(argv[1]);
	if (line_nbr != -1)
		matrix = get_matrix_altitude(argv[1], line_nbr);
	(void)matrix;
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
