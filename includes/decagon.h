/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decagon.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:53:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/31 15:54:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECAGON_H
# define DECAGON_H

typedef struct		s_decagon
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
	t_vector		*p10;
	double			reflection;
	double			transparency;
	double			brilliance;
	double			size;
	int				regular;
	int				color;
}					t_decagon;

#endif
