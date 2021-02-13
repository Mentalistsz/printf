#include "ft_printf.h"

int	ft_type_id(t_format *ft, va_list *args, int i)
{
	char			*s;
	int				len;

	i = va_arg(*args, int);
	if (!(s = ft_itoa(i)))
		return (0);
	len = ft_strlen(s);
	if (ft->precision >= 0 && ft->width > 0 && ft->flag == '0')
		ft->flag = ' ';
	if (s[0] == '-' && ft->precision != -1)
		ft->precision++;
	if (ft->precision > 0)
		if (!ft_precision(ft, &s, len))
			return (0);
	len = ft_strlen(s);
	if (ft->precision == 0 && i == 0)
		len = ft_width(ft, "", 0, 0);
	else
		len = ft_width(ft, s, len, 0);
	free(s);
	return (len);
}

int	ft_type_u(t_format *ft, va_list *args)
{
	char			*s;
	int				len;
	unsigned int	n;

	n = 1;
	n = va_arg(*args, unsigned int);
	if (!(s = ft_utoa(n)))
		return (0);
	len = ft_strlen(s);
	if (ft->precision >= 0 && ft->width > 0 && ft->flag == '0')
		ft->flag = ' ';
	if (ft->precision > 0)
		if (!ft_precision(ft, &s, len))
			return (0);
	len = ft_strlen(s);
	if (ft->precision == 0 && n == 0)
		len = ft_width(ft, "", 0, 0);
	else
		len = ft_width(ft, s, len, 0);
	free(s);
	return (len);
}

int	ft_type_s(t_format *ft, va_list *args)
{
	char	*s;
	int		len;
	int		out;

	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (ft->precision < len)
		if (!(s = ft_substr(s, 0, ft->precision)))
			return (0);
	out = ft_width(ft, s, ft_strlen(s), 0);
	if (ft->precision < len)
		free(s);
	return (out);
}

int	ft_type_c(t_format *ft, va_list *args)
{
	char	c;
	int		out;

	out = 0;
	if (ft->type == '%')
		c = '%';
	else
		c = (char)va_arg(*args, int);
	if (ft->flag == '-')
	{
		out += ft_putchar_fd(c, 1);
		while (ft->width > 1)
		{
			out += ft_putchar_fd(' ', 1);
			ft->width--;
		}
		return (out);
	}
	while (ft->width > 1)
	{
		out += ft_putchar_fd(ft->flag, 1);
		ft->width--;
	}
	out += ft_putchar_fd(c, 1);
	return (out);
}
