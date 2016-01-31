/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octahedron.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 11:37:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 11:38:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCTAHEDRON_H
# define OCTAHEDRON_H

typedef struct		s_octahedron
{
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	t_Vector		*p6;
}					t_octahedron;

#endif
