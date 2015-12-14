/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 07:43:51 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/14 08:14:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

void	vector_normalize(t_vector *vector)
{
	double	length;

	length = vector_size(vector);
	if (length != 0)
	{
		vector->x = vector->x / length;
		vector->y = vector->y / length;
		vector->z = vector->z / length;
	}
}