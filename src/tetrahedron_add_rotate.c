/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_add_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:35:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:36:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	tetrahedron_add_rotate(t_tetrahedron *tetrahedron)
{
	vector_rotate(tetrahedron->p1, tetrahedron->rotation);
	vector_rotate(tetrahedron->p2, tetrahedron->rotation);
	vector_rotate(tetrahedron->p3, tetrahedron->rotation);
	vector_rotate(tetrahedron->p4, tetrahedron->rotation);
}
