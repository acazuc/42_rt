/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_add_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:52:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 13:53:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*cube_add_point_1(t_cube *cube, int face)
{
	if (face == 1)
		return (cube->p1);
	else if (face == 2)
		return (cube->p6);
	else if (face == 3)
		return (cube->p5);
	else if (face == 4)
		return (cube->p4);
	else if (face == 5)
		return (cube->p5);
	else
		return (cube->p2);
}

t_vector	*cube_add_point_2(t_cube *cube, int face)
{
	if (face == 1)
		return (cube->p2);
	else if (face == 2)
		return (cube->p5);
	else if (face == 3)
		return (cube->p6);
	else if (face == 4)
		return (cube->p3);
	else if (face == 5)
		return (cube->p1);
	else
		return (cube->p6);
}

t_vector	*cube_add_point_3(t_cube *cube, int face)
{
	if (face == 1)
		return (cube->p3);
	else if (face == 2)
		return (cube->p8);
	else if (face == 3)
		return (cube->p2);
	else if (face == 4)
		return (cube->p7);
	else if (face == 5)
		return (cube->p4);
	else
		return (cube->p7);
}

t_vector	*cube_add_point_4(t_cube *cube, int face)
{
	if (face == 1)
		return (cube->p4);
	else if (face == 2)
		return (cube->p7);
	else if (face == 3)
		return (cube->p1);
	else if (face == 4)
		return (cube->p8);
	else if (face == 5)
		return (cube->p8);
	else
		return (cube->p3);
}
