/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:40:52 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/11 14:05:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_object	*create_sphere(void)
{
	t_object	*sphere;

	sphere = object_create();
	sphere->type = SPHERE;
	return (sphere);
}
