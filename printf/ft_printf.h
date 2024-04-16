/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:36 by matmaca           #+#    #+#             */
/*   Updated: 2023/11/13 15:25:11 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr( int n);
int		ft_hex(unsigned int n, char c);
int		ft_pointer(unsigned long int num, int check);
int		ft_unsign(unsigned int num);
char	*ft_itoa(int n);

#endif
