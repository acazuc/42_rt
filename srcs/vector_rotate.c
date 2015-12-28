/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 10:16:24 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:46:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	vector_rotate(t_vector *vector, t_vector *rotation)
{
	vector_rotate_z(vector, DTR(rotation->z));
	vector_rotate_y(vector, DTR(rotation->y));
	vector_rotate_x(vector, DTR(rotation->x));
}

void	vector_unrotate(t_vector *vector, t_vector *rotation)
{
	vector_rotate_x(vector, DTR(-rotation->x));
	vector_rotate_y(vector, DTR(-rotation->y));
	vector_rotate_z(vector, DTR(-rotation->z));
}
