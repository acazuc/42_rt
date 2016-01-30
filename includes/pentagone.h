/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pentagone.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:54:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 13:56:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENTAGONE_H
# define PENTAGONE_H

typedef struct	s_pentagone
{
	t_vector	*p1;
	t_vector	*p2;
	t_vector	*p3;
	t_vector	*p4;
	t_vector	*p5;
	double		brilliance;
	double		reflection;
	double		transparency;
	int			color;
}				t_pentagone;

#endif
