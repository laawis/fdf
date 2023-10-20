/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:32 by gaollier          #+#    #+#             */
/*   Updated: 2023/10/19 14:40:25 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(const t_data *const data, const int x, const int y, const int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// le premier const signifie que cee qui est pointe (valeur) est constant
// 2ieme const signifie que la valeur du pointeur est constant
void	draw_point(const t_data *const data, const t_vertex *const vertex)
{
	if ((vertex->x <= WINDOW_WIDTH && vertex->x >= 0) && (vertex->y <= WINDOW_HEIGHT && vertex->y >= 0))
		my_mlx_pixel_put(data, vertex->x, vertex->y, vertex->color);
}
