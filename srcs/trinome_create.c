/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trinome_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 09:53:40 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/19 08:38:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rt.h"

t_trinome	*trinome_create(void)
{
	t_trinome	*trinome;

	if (!(trinome = malloc(sizeof(*trinome))))
		error_quit("Failed to malloc trinome");
	trinome->a = 0;
	trinome->b = 0;
	trinome->c = 0;
	trinome->d = 0;
	return (trinome);
}
