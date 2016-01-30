/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:53:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 10:54:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rectangle_free(t_rectangle *rectangle)
{
	free(rectangle->p1);
	free(rectangle->p2);
	free(rectangle->p3);
	free(rectangle->p4);
	free(rectangle);
}
