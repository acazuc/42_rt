/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:40:52 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/15 14:42:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_object	*create_cone(void)
{
	t_object	*cone;

	cone = object_create();
	cone->type = CONE;
	return (cone);
}
