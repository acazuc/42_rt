/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_data_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:20:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 15:23:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light_data	*light_data_create(void)
{
	t_light_data	*data;

	if (!(data = malloc(sizeof(*data))))
		error_quit("Failed to malloc light data");
	data->mask = NULL;
	data->spec = NULL;
	return (data);
}
