/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:24:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 09:25:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	octahedron_free(t_octahedron *octahedron)
{
	free(octahedron->position);
	free(octahedron->rotation);
	free(octahedron->p1);
	free(octahedron->p2);
	free(octahedron->p3);
	free(octahedron->p4);
	free(octahedron->p5);
	free(octahedron->p6);
	free(octahedron);
}
