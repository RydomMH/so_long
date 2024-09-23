/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr4u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:22:49 by rmiah             #+#    #+#             */
/*   Updated: 2024/05/28 13:22:51 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr4u(unsigned int nb)
{
	int	compteur;

	compteur = 0;
	if (nb >= 10)
		compteur = compteur + ft_putnbr(nb / 10);
	compteur = compteur + ft_putchar((nb % 10) + '0');
	return (compteur);
}
