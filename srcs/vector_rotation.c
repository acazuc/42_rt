/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 11:58:48 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/16 08:11:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	vector_rotate_x(t_vector *vector, double angle)
{
	double		temp_y;
	double		temp_z;

	temp_y = vector->y;
	temp_z = vector->z;
	vector->y = temp_y * cos(angle) - temp_z * sin(angle);
	vector->z = temp_y * sin(angle) + temp_z * cos(angle);
}

void	vector_rotate_y(t_vector *vector, double angle)
{
	double		temp_x;
	double		temp_z;

	temp_x = vector->x;
	temp_z = vector->z;
	vector->z = temp_z * cos(angle) - temp_x * sin(angle);
	vector->x = temp_z * sin(angle) + temp_x * cos(angle);
}

void	vector_rotate_z(t_vector *vector, double angle)
{
	double		temp_x;
	double		temp_y;

	temp_x = vector->x;
	temp_y = vector->y;
	vector->x = temp_x * cos(angle) - temp_y * sin(angle);
	vector->y = temp_x * sin(angle) + temp_y * cos(angle);
}
