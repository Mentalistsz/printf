#include "ft_printf.h"

int	ft_handler(t_format *ft, va_list *args)
{
	int out;

	out = 0;
	if (ft->type == 'd' || ft->type == 'i')
		out = ft_type_id(ft, args, 1);
	if (ft->type == 's')
		out = ft_type_s(ft, args);
	if (ft->type == 'c' || ft->type == '%')
		out = ft_type_c(ft, args);
	if (ft->type == 'u')
		out = ft_type_u(ft, args);
	if (ft->type == 'x' || ft->type == 'X')
		out = ft_type_x(ft, args);
	if (ft->type == 'p')
		out = ft_type_p(ft, args);
	return (out);
}

int	ft_precision(t_format *ft, char **s, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (len < ft->precision)
	{
		if (!(temp = (char *)malloc(sizeof(char) * (ft->precision + 1))))
			return (0);
		temp[ft->precision] = '\0';
		if ((*s)[0] == '-')
		{
			temp[i++] = '-';
			(*s)[0] = '0';
		}
		while (i < (ft->precision - len))
			temp[i++] = '0';
		while (i < ft->precision)
		{
			temp[i] = (*s)[i - (ft->precision - len)];
			i++;
		}
		free(*s);
		*s = temp;
	}
	return (1);
}

int	ft_width(t_format *ft, char *s, int len, int out)
{
	if (len < ft->width)
	{
		if (ft->flag == '-')
		{
			out += ft_putstr_fd(s, 1);
			while (out < ft->width)
				out += ft_putchar_fd(' ', 1);
			return (out);
		}
		if ((ft->type == 'd' || ft->type == 'i') &&
		s[0] == '-' && ft->flag == '0')
		{
			out += ft_putchar_fd('-', 1);
			s[0] = ft->flag;
			len++;
		}
		while (len < ft->width)
		{
			out += ft_putchar_fd(ft->flag, 1);
			len++;
		}
	}
	out += ft_putstr_fd(s, 1);
	return (out);
}
