/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:47 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/16 13:52:15 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT	500
# define WIDTH	500

#include <stdint.h>
#include <libft.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef unsigned int uint;

struct s_vertex
{
	int x;
	int y;
	int w;
	uint color;
};
typedef struct s_vertex t_vertex;

int		main(int argc, char **argv);
void	print_matrix_altitude(char ***const matrix_altitude);
char	***fill_matrix(char ***matrix_altitude, const char *const filename);
char	***get_matrix_altitude(const char *const filename, const size_t nb_line);
int		get_line_number(char *const filename);
void	free_strings(char **string_array);
void	free_matrix_altitude(char ***matrix_altitude);
void	draw_point(const t_data *const data, const t_vertex *const vertex);

#endif
