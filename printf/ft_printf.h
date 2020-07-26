/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:36:39 by tnakamur          #+#    #+#             */
/*   Updated: 2020/07/27 00:52:17 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	char		zero;
	const char	*pt;
	int			width;
	int			minus;
	int			prec;
	int			ag;
	int			field;
	int			star;
	int			dot;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_output(const char *fmt, va_list ap, t_flag f);
int				decide_type(va_list ap, t_flag f, const char *fmt);

int				minus_chr(const char *fmt, t_flag f);
char			zero_chr(const char *fmt, t_flag f);

t_flag			reset_flag(t_flag f);
t_flag			width_reset(t_flag f);
t_flag			width_star(t_flag f, va_list ap);
t_flag			prec_flag(t_flag f, va_list ap, const char *fmt);
t_flag			parse_flag(t_flag f, const char *fmt, va_list ap);

char			*ft_uitoa(int n);
char			*ft_hextoa_0x(unsigned long n);
char			*ft_hextoa(unsigned long n, char x);

int				is_type(char c);
int				ad_len(int ag, int len, int d);
char			*sp_zero(int w, char c);
char			*zero(int w);
void			hex_upper(char *str);

char			*ft_strjoin_free(char *s1, char *s2);
void			free_set(char *s1, char *s2);
int				is_flag(char c);
int				ft_putchar_per(char c, int fd, t_flag f);
char			*itos_for_d(int n, t_flag f);

int				ft_output_d(va_list ap, t_flag f, int len);
int				ft_output_u(va_list ap, t_flag f, int len);
int				ft_output_p(va_list ap, t_flag f, int len);
int				ft_output_x(va_list ap, t_flag f, int len);
int				ft_output_lx(va_list ap, t_flag f, int len);

int				ft_output_s(va_list ap, t_flag f, int len);
int				ft_output_c(va_list ap, t_flag f, int len);
int				ft_output_per(int ag, t_flag f, int len);
int				ft_padding(char c, int n);
char			*dup_and_free(char *val, char *s);

char			*prec_join(char *str, long n, int size);
char			*wide_join(char *str, char *sp, long n, t_flag f);
char			*prec_join_0x(char *val, t_flag f);
char			*wide_join_0x(char *sp, char *str, t_flag f);
char			*precjoin_free(char *str, int size);

#endif
