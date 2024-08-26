/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:40 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 15:52:49 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_print_char(int c);
int		ft_print_num(int c);
int		ft_print_hex(unsigned int h, const char format);
int		ft_print_str(char	*str);
int		ft_print_percent(void);
int		ft_print_unint(unsigned int n);
int		ft_putaddress(char *c);
int		ft_printf(const char *str, ...);

#endif