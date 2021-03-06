/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 10:16:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 16:42:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	vector_rotate(t_vector *vector, t_vector *rotation)
{
	vector_rotate_x(vector, DTR(rotation->x));
	vector_rotate_y(vector, DTR(rotation->y));
	vector_rotate_z(vector, DTR(rotation->z));
}

void	vector_unrotate(t_vector *vector, t_vector *rotation)
{
	vector_rotate_z(vector, -(DTR(rotation->z)));
	vector_rotate_y(vector, -(DTR(rotation->y)));
	vector_rotate_x(vector, -(DTR(rotation->x)));
}
