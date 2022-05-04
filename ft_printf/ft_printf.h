/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:11:08 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/02 19:37:53 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	int		len;
	int		digit;
	int		ret;
	char	*prefix;
	int		sharp;
	int		minus;
	int		zero;
	int		dot;
	int		prec;
	int		buffer;
	int		padding;
	char	fill;
	char	first_sign;
	char	*base;
	int		error;
}	t_print;

// Printf.c
int		ft_isdigit(char c);
int		ft_check_type(char c);
void	ft_printinit(t_print *print, int ret);
int		ft_printf(const char *fmt, ...);

// Print_args.c
void	ft_print_char(char c, t_print *print);
void	ft_print_str(char *str, t_print *print);
void	ft_print_number(int num, t_print *print);
void	ft_print_basenum(size_t num, t_print *print, char c);
void	ft_printargs(t_print *print, const char *fmt, va_list *ap);

// Print_out.c
void	ft_print(char *str, int len, t_print *print);
void	ft_print_num(char *str, int len, t_print *print);
void	ft_print_buffer(char c, int len, t_print *print);

// Flag.c
void	ft_prec(t_print *print, char **fmt);
void	ft_width(t_print *print, char **fmt);
void	ft_flag(t_print *print, char **fmt);
void	ft_make_fill(t_print *print, int num, char type);
size_t	ft_type(char type, t_print *print, size_t num);

// Utils.c
int		ft_strlen(char *str);
size_t	ft_num_len(ssize_t num, t_print *print);
size_t	ft_basenum_len(size_t num, int base_len, t_print *print);
char	*ft_to_base(size_t num, t_print *print);
char	*ft_itoa(int num, t_print *print);

#endif