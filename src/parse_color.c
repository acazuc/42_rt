/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:11:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/30 11:10:27 by acazuc           ###   ########.fr       */
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

static int	parse_hexa(t_parser *p)
{
	int		red;
	int		green;
	int		blue;

	if (ft_strlen(p->datas[p->count]) != 7 || p->datas[p->count][0] != '#')
		parse_error(p, "Failed to parse hexa color");
	red = get_char_value(p->datas[p->count][1]) * 16 +
		get_char_value(p->datas[p->count][2]);
	green = get_char_value(p->datas[p->count][3]) * 16 +
		get_char_value(p->datas[p->count][4]);
	blue = get_char_value(p->datas[p->count][5]) * 16 +
		get_char_value(p->datas[p->count][6]);
	return ((red << 16) + (green << 8) + blue);
}

int			parse_color(t_parser *p)
{
	p->count++;
	if (!p->datas[p->count])
		parse_error(p, "Failed to read color");
	if (!ft_strcmp(p->datas[p->count], "RED"))
		return (RED);
	else if (!ft_strcmp(p->datas[p->count], "GREEN"))
		return (GREEN);
	else if (!ft_strcmp(p->datas[p->count], "BLUE"))
		return (BLUE);
	else if (!ft_strcmp(p->datas[p->count], "YELLOW"))
		return (YELLOW);
	else if (!ft_strcmp(p->datas[p->count], "MAGENTA"))
		return (MAGENTA);
	else if (!ft_strcmp(p->datas[p->count], "CYAN"))
		return (CYAN);
	else if (!ft_strcmp(p->datas[p->count], "BLACK"))
		return (BLACK);
	else if (!ft_strcmp(p->datas[p->count], "GREY"))
		return (GREY);
	else if (!ft_strcmp(p->datas[p->count], "WHITE"))
		return (WHITE);
	return (parse_hexa(p));
}
