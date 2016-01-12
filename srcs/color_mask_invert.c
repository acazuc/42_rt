/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mask_invert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:41:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/09 14:51:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	color_mask_invert(t_color_mask *mask)
{
	mask->red = 1 - mask->red;
	mask->green = 1 - mask->green;
	mask->blue = 1 - mask->blue;
}
