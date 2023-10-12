
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>

#include "fdf.h"

static void	rm_newline_char_instring(char *const line)
{
	const size_t	len = ft_strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

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
		rm_newline_char_instring(line);
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
	return (matrix_altitude);
}

int	get_line_number(char *const filename)
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
