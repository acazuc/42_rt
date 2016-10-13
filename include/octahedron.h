/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 11:37:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/01 09:47:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCTAHEDRON_H
# define OCTAHEDRON_H

typedef struct		s_octahedron
{
	t_vector		*position;
	t_vector		*rotation;
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	t_vector		*p6;
	double			reflection;
	double			transparency;
	double			brilliance;
	double			size;
	int				regular;
	int				color;
}					t_octahedron;

#endif
