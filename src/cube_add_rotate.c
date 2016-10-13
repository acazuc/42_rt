/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_add_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:32:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:32:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cube_add_rotate(t_cube *cube)
{
	vector_rotate(cube->p1, cube->rotation);
	vector_rotate(cube->p2, cube->rotation);
	vector_rotate(cube->p3, cube->rotation);
	vector_rotate(cube->p4, cube->rotation);
	vector_rotate(cube->p5, cube->rotation);
	vector_rotate(cube->p6, cube->rotation);
	vector_rotate(cube->p7, cube->rotation);
	vector_rotate(cube->p8, cube->rotation);
}
