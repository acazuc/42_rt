/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 11:58:48 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/13 14:37:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	vector_rotate_x(t_vector *vector, double angle)
{
	double		temp_y;

	temp_y = vector->y;
	vector->y = vector->y * cos(angle) - vector->z * sin(angle);
	vector->z = temp_y * sin(angle) + vector->z * cos(angle);
}

void	vector_rotate_y(t_vector *vector, double angle)
{
	double		temp_z;

	temp_z = vector->z;
	vector->z = vector->z * cos(angle) - vector->x * sin(angle);
	vector->x = temp_z * sin(angle) + vector->x * cos(angle);
}

void	vector_rotate_z(t_vector *vector, double angle)
{
	double		temp_x;

	temp_x = vector->x;
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = temp_x * sin(angle) + vector->y * cos(angle);
}
