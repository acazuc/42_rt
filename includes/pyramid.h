/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:51:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 16:52:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_H
# define PYRAMID_H

typedef struct		s_pyramid
{
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	double			reflection;
	double			transparency;
	double			brilliance;
	int				color;
}					t_pyramid;

#endif
