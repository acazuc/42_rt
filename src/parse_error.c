/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:54:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/28 16:11:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_error(t_parser *parser, char *message)
{
	ft_putstr("\033[1;31mParsing error: ");
	ft_putstr(message);
	ft_putstr(" (");
	ft_putstr(parser->file);
	ft_putchar(':');
	ft_putnbr(parser->line);
	ft_putendl(")\033[0;47m");
	exit(1);
}
