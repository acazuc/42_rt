/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:20:07 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:46:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*vector_multiply(t_vector *vector, double factor)
{
	t_vector	*new_vector;

	new_vector = vector_create();
	new_vector->x = vector->x * factor;
	new_vector->y = vector->y * factor;
	new_vector->z = vector->z * factor;
	return (new_vector);
}
