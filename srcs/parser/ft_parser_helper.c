/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:25:53 by svet              #+#    #+#             */
/*   Updated: 2020/08/18 10:04:20 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <sys/_types/_null.h>

void	fmt_revise_flags(char type, t_fmt *fmt)
{
	if (type == 'D' || type == 'U' || type == 'O' || type == 'S' || type == 'C')
		fmt->flags |= FL_LONGINT;
	else if (ft_memchr("XFEGAP", type, 6) != NULL)
		fmt->flags |= FL_UPPER;
	else if (type == 'd' || type == 'i' || type == 'D')
		fmt->flags |= FL_SIGNED;
	else if (type == 'D')
		fmt->flags |= FL_LONGINT | FL_SIGNED;
}

void	fmt_upd_flags(int flag, t_fmt *fmt)
{
	int flags;

	flags = fmt->flags;
	flags |= flag;
	if (flag & FL_LADJUST)
		flags &= ~FL_ZEROPAD;
	fmt->flags = flags;
}