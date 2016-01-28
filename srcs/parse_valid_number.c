/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:24:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:40:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parse_valid_number(char *data)
{
	int		dot_count;
	int		i;

	dot_count = 0;
	i = 0;
	while (data[i])
	{
		if ((data[i] < '0' || data[i] > '9') && data[i] != '.'
				&& data[i] != '-')
			return (0);
		if (data[i] == '-' && i != 0)
			return (0);
		if (data[i] == '.')
		{
			if (dot_count)
				return (0);
			dot_count = 1;
		}
		i++;
	}
	return (1);
}
