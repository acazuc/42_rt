/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:32:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 16:16:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	collision_free(t_collision *collision)
{
	if (collision)
	{
		free(collision->vector);
		free(collision->normal);
		free(collision);
	}
}
