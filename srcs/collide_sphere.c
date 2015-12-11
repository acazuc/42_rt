/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:49:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 15:30:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

double	collide_sphere(t_vector *vector, t_object *object)
{
	vector = vector + 1;
	vector = vector - 1;
	object = object + 1;
	object = object - 1;
	return (0);
}
