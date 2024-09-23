/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:05:19 by rmiah             #+#    #+#             */
/*   Updated: 2024/07/03 12:48:29 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalower(unsigned int nb)
{
	char	*str;
	int		compteur;

	compteur = 0;
	str = "0123456789abcdef";
	if (nb >= 16)
		compteur = compteur + ft_hexalower(nb / 16);
	compteur = compteur + ft_putchar(str[nb % 16]);
	return (compteur);
}

/*int	main(void)
{
	int	nb = 32;
	ft_hexalower(nb);
}*/