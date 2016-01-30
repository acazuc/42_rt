/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:31:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 15:34:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXAGON_H
# define HEXAGON_H

typedef struct		s_hexagon
{
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	t_vector		*p6;
	double			reflection;
	double			transparency;
	double			brilliance;
	int				color;
}					t_hexagon;

#endif
