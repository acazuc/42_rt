/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mask_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 09:11:05 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/16 10:17:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rtv1.h"

t_color_mask	*color_mask_create(void)
{
	t_color_mask	*mask;

	if (!(mask = malloc(sizeof(*mask))))
		error_quit("Failed to malloc color mask");
	mask->red = 0;
	mask->green = 0;
	mask->blue = 0;
	return (mask);
}
