/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sptag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 06:02:27 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 07:49:31 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_sptag(char **str)
{
	if ((*str)[0] == ' ')
		return ;
	if ((*str)[0] == '0')
		(*str)[0] = ' ';
	else
		*str = ft_strjoin_free(" ", 0, *str, 1);
}
