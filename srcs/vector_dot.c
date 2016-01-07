/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 07:20:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/07 11:21:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	vector_dot(t_vector *v1, t_vector *v2)
{
	return (sqrt(v1->x * v2->x + v1->y * v2->y + v1->z * v2->z));
}
