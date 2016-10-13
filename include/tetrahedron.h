/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 08:52:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 11:46:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAHEDRON_H
# define TETRAHEDRON_H

typedef struct		s_tetrahedron
{
	t_vector		*position;
	t_vector		*rotation;
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	double			reflection;
	double			transparency;
	double			brilliance;
	double			size;
	int				regular;
	int				color;
}					t_tetrahedron;

#endif
