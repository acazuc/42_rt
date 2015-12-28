/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:04:15 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:46:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*vector_create(void)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(*vector))))
		error_quit("Failed to malloc new vector");
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
	return (vector);
}
