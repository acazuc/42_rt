/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_data_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:26:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/21 15:29:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	light_data_free(t_light_data *data)
{
	free(data->mask);
	free(data->spec);
	free(data);
}
