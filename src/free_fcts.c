
#include <stdlib.h>
#include <sys/types.h>

#include "fdf.h"

void	free_vertex_matrix(t_vertex **vertex_matrix, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(vertex_matrix[i]);
		i++;
	}
	free(vertex_matrix);
}

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
