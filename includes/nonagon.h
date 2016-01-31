/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonagon.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:50:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:52:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NONOGON_H
# define NONAGON_H

typedef struct		s_nonagon
{
	t_vector		*position;
	t_vector		*rotation;
	t_vector		*p1;
	t_vector		*p2;
	t_vector		*p3;
	t_vector		*p4;
	t_vector		*p5;
	t_vector		*p6;
	t_vector		*p7;
	t_vector		*p8;
	t_vector		*p9;
	double			reflection;
	double			transparency;
	double			brilliance;
	double			size;
	int				regular;
	int				color;
}					t_nonagon;

#endif
