/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:55:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/04/09 15:01:45 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}