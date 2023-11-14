/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <gaollier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:32 by gaollier          #+#    #+#             */
/*   Updated: 2023/11/13 14:54:42 by gaollier         ###   ########.fr       */
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
/*
void	line(t_data *data, t_vertex *vertex1, t_vertex *vertex2)
{

//	int	dx = vertex2->x - vertex1->x;
//	int	dy = vertex2->y - vertex1->y;
//	int	coeff = dy / dx;
//	int	e = dx;
//
//
//
//
//


	int	ex = (vertex2->x - vertex1->x);
	int	ey = (vertex2->y - vertex1->y);
	int	dx = 2 * ex;
	int	dy = 2 * ey;
	int	Dx = ex;
	int	Dy = ey

	int	Xincr = 1;
	int	Yincr = 1;
	int	i;


// TRANSFORMATION FLOAT TO INT :

//	int	dx = (vertex2->x - vertex1->x);
//	int	dy = (vertex2->y - vertex1->y);
//	float	m = dy / dx;	* dx // m = dy; //PLUS BESOIN DE m
//	float	ex = 0.5;	* dx * 2

	if (dx < 0)
		dx = dx * -1;
	if (dy < 0)
		dy = dy * -1;

	if (vertex1->x > vertex2->x)
		Xincr = -1;
	if (vertex1->y > vertex2->y)
		Yincr = -1;

	i = 0;
	if (Dx > Dy)
	{
		while (i <= Dx)
		{

			draw_point()
			//my_mlx_pixel_put(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->x += Xincr
			ex -= dy;
			if (ex < 0)
			{
				vertex1->y += Yincr;
				ex += dx;
			}
			i++;
		}
	}
	if (Dx < Dy)
	{
		while (i <= Dy)
		{

			draw_point()
			//my_mlx_pixel_put(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->y += Yincr
			ey -= dx;
			if (ey < 0)
			{
				vertex1->x += Xincr;
				ey += dy;
			}
			i++;
		}
	}
}
*/

void	draw_line(t_data *data, t_vertex *vertex1, t_vertex *vertex2)
{
	int	ex = (vertex2->x - vertex1->x);
	int	ey = (vertex2->y - vertex1->y);
	int	dx;
	int	dy;
	int	Dx;
	int	Dy;
	int	Xincr = 1;
	int	Yincr = 1;
	int	i;

	if (ex < 0)
		ex *= -1;
	if (ey < 0)
		ey *= -1;
	dx = 2 * ex;
	dy = 2 * ey;
	Dx = ex;
	Dy = ey;
	if (vertex1->x > vertex2->x)
		Xincr = -1;
	if (vertex1->y > vertex2->y)
		Yincr = -1;
	i = 0;
	if (Dx > Dy)
	{
		while (i <= Dx)
		{
			draw_point(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->x += Xincr;
			ex -= dy;
			if (ex < 0)
			{
				vertex1->y += Yincr;
				ex += dx;
			}
			i++;
		}
	}
	else if (Dx < Dy)
	{
		while (i <= Dy)
		{
			draw_point(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->y += Yincr;
			ey -= dx;
			if (ey < 0)
			{
				vertex1->x += Xincr;
				ey += dy;
			}
			i++;
		}
	}
	else if (Dx == Dy)
	{
		while (i <= Dx)
		{
			draw_point(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->x += Xincr;
			vertex1->y += Yincr;
		}
		i++;
	}
	else if (Dx == 0)
	{
		while (i <= Dy)
		{
			draw_point(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->y += Yincr;
		}
		i++;
	}
	else if (Dy == 0)
	{
		while (i <= Dx)
		{
			draw_point(data, vertex1->x, vertex1->y, 0x00FFFFFF);
			vertex1->x += Xincr;
		}
		i++;
	}
}
