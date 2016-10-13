/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:23:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:58:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pentagon_free(t_pentagon *pentagon)
{
	free(pentagon->position);
	free(pentagon->rotation);
	free(pentagon->p1);
	free(pentagon->p2);
	free(pentagon->p3);
	free(pentagon->p4);
	free(pentagon->p5);
	free(pentagon);
}
