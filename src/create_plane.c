/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 07:15:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/05 07:16:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object	*create_plane(void)
{
	t_object	*plane;

	plane = object_create();
	plane->type = PLANE;
	return (plane);
}
