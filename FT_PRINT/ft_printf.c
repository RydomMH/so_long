/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:51:25 by rmiah             #+#    #+#             */
/*   Updated: 2024/07/01 15:39:23 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_charset(char c)
{
	int		i;
	char	b;
	char	*charset;

	charset = "sdcxXpui";
	b = '%';
	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i] || c == b)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		compteur;
	va_list	args;

	i = 0;
	compteur = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (check_charset(str[i + 1]) == 1)
				compteur = compteur + ft_usefunction(args, str[++i]);
			else
				return (-1);
		}
		else
			compteur = compteur + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (compteur);
}

/*int	main(void)
{
	int	result;
	char	tab[] = "Rydom";

	result = ft_printf("Salut Comment Ca Va %s ?", tab);
	printf("\n");
	printf("Nombre de caracteres : [%d]", result);
	return (0);
}*/
