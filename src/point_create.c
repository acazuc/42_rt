/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:17:14 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:45:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point		*point_create(void)
{
	t_point		*point;

	if (!(point = malloc(sizeof(*point))))
		error_quit("Failed to malloc new point");
	point->x = 0;
	point->y = 0;
	return (point);
}
