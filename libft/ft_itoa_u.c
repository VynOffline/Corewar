/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:43:54 by czalewsk          #+#    #+#             */
/*   Updated: 2017/01/13 03:36:38 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_int_len(uintmax_t n)
{
	int		i;

	i = 1;
	while (!(n < 10))
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_u(uintmax_t n)
{
	int		i;
	char	*nb;

	i = ft_int_len(n);
	if (!(nb = ft_strnew(i)))
		return (NULL);
	while (i >= 1)
	{
		nb[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (nb);
}
