
#include <libft.h>

#include "fdf.h"

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
			ft_printf("[%s]", matrix_altitude[i][j]); // plus simple
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
