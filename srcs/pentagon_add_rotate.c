/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagon_add_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:06:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:07:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	pentagon_add_rotate(t_pentagon *pentagon)
{
	vector_rotate(pentagon->p1, pentagon->rotation);
	vector_rotate(pentagon->p2, pentagon->rotation);
	vector_rotate(pentagon->p3, pentagon->rotation);
	vector_rotate(pentagon->p4, pentagon->rotation);
	vector_rotate(pentagon->p5, pentagon->rotation);
}
