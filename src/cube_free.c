/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:31:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 14:57:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cube_free(t_cube *cube)
{
	free(cube->position);
	free(cube->rotation);
	free(cube->p1);
	free(cube->p2);
	free(cube->p3);
	free(cube->p4);
	free(cube->p5);
	free(cube->p6);
	free(cube);
}
