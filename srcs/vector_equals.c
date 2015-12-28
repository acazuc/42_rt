/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:18:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/27 14:46:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		vector_equals(t_vector *v1, t_vector *v2)
{
	return (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z);
}
