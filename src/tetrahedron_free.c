/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 08:58:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 11:47:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	tetrahedron_free(t_tetrahedron *tetrahedron)
{
	free(tetrahedron->position);
	free(tetrahedron->rotation);
	free(tetrahedron->p1);
	free(tetrahedron->p2);
	free(tetrahedron->p3);
	free(tetrahedron->p4);
	free(tetrahedron);
}
