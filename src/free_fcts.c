
#include <stdlib.h>

#include "fdf.h"

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
