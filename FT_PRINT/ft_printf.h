/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiah <rmiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:52:47 by rmiah             #+#    #+#             */
/*   Updated: 2024/09/16 19:38:35 by rmiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <bsd/string.h>
# include <stddef.h>
# include <stdarg.h>

int			ft_putstr(char *str);
int			ft_usefunction(va_list args, char c);
int			ft_putnbr(int nb);
int			ft_putchar(int c);
int			ft_putnbr4u(unsigned int nb);
int			ft_hexalower(unsigned int nb);
int			ft_hexaupper(unsigned int nb);
int			ft_printf(const char *str, ...);

#endif
