/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:11:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/29 16:33:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_char_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	error_quit("Invalid hexa color char");
	return (0);
}

static int	parse_hexa(char *str)
{
	int		red;
	int		green;
	int		blue;

	if (ft_strlen(str) != 7 || str[0] != '#')
		error_quit("Failed to parse hexa color");
	red = get_char_value(str[1]) * 16 + get_char_value(str[2]);
	green = get_char_value(str[3]) * 16 + get_char_value(str[4]);
	blue = get_char_value(str[5]) * 16 + get_char_value(str[6]);
	return ((red << 16) + (green << 8) + blue);
}

int			parse_color(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "RED"))
		return (RED);
	else if (!ft_strcmp(str, "GREEN"))
		return (GREEN);
	else if (!ft_strcmp(str, "BLUE"))
		return (BLUE);
	else if (!ft_strcmp(str, "YELLOW"))
		return (YELLOW);
	else if (!ft_strcmp(str, "MAGENTA"))
		return (MAGENTA);
	else if (!ft_strcmp(str, "CYAN"))
		return (CYAN);
	else if (!ft_strcmp(str, "BLACK"))
		return (BLACK);
	else if (!ft_strcmp(str, "GREY"))
		return (GREY);
	else if (!ft_strcmp(str, "WHITE"))
		return (WHITE);
	return (parse_hexa(str));
}
