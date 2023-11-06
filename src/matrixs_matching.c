#include <stdlib.h>
#include <sys/types.h>
#include <libft.h>

#include "fdf.h"

ssize_t	get_width(char ***matrix_altitude)
{
	size_t	i;
	size_t	j;
	size_t	width;

	width = 0;
	i = 0;
	while (matrix_altitude[i] != NULL)
	{
		j = 0;
		while(matrix_altitude[i][j] != NULL && j < MAP_WIDTH_LIMIT)
		{
			j++;
		}
		if ((j != width && i > 0) || j > MAP_WIDTH_LIMIT)
			return (-1);
		width = j;
		i++;
	}
	return (width);
}

t_vertex	**alloc_vertex_matrix(size_t width, size_t height)
{
	t_vertex	**vertex_matrix;
	size_t		i;

	vertex_matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (height));
	if (vertex_matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		vertex_matrix[i] = ((t_vertex *)malloc(sizeof(t_vertex) * (width)));
		if (vertex_matrix[i] == NULL)
		{
			free_vertex_matrix(vertex_matrix, i);
			return (NULL);
		}
		i++;
	}
	return (vertex_matrix);
}

t_vertex	**fill_vertex_matrix(t_vertex **vertex_matrix, char ***string_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (string_matrix[i] != NULL)
	{
		j = 0;
		while (string_matrix[i][j] != NULL)
		{
			vertex_matrix[i][j].y = i;
			vertex_matrix[i][j].x = j;
			vertex_matrix[i][j].w = ft_atoi(string_matrix[i][j]);
			j++;
		}
		i++;
	}
	return (vertex_matrix);
}



/*

struct s_map
{
	t_vertex	**matrix;
	size_t		height;
	size_t		width;
}

height
width

matrix_vertex =
{
	{v1, v2, v3, v4},
	{...}
	{...}
	{...}
}	 NULL

	ADDRESS		|	VALUE	|	SYMBOL
				|			|
	100			|	'n'		|	str[0]
	101			|	'o'		|	str[1]
	102			|	'n'		|	str[2]
	103			|	'['		|	str[3]
	104			|	'['		|	str[4]
	105			|	'['		|	str[5]
	106			|	'['		|	str[6]
	107			|	'['		|	str[7]
	108			|	'['		|	str[8]
	109			|	'['		|	str[9]
	110			|	'['		|	str[10]
				|			|
				|			|
	...			|			|
				|			|
	500			|	100		|	str

str = ft_strdup("hello");

struct s_string
{
	char	*content;
	size_t	len;
}


*/
