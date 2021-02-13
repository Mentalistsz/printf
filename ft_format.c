#include "ft_printf.h"

int		ft_useless(const char *s, t_format *ft, va_list *args, int i)
{
	if (s[i] == '.')
	{
		i++;
		ft->precision = 0;
		if (s[i] == '-')
			ft->flag = s[i++];
		while (s[i] >= '0' && s[i] <= '9')
			ft->precision = ft->precision * 10 + (s[i++] - 48);
		if (s[i] == '*')
		{
			if ((ft->precision = va_arg(*args, int)) < 0)
				ft->precision = -1;
			i++;
		}
	}
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p'
	|| s[i] == 'd' || s[i] == 'i' || s[i] == 'u'
	|| s[i] == 'x' || s[i] == 'X' || s[i] == '%')
	{
		ft->type = s[i++];
		return (i);
	}
	return (-999);
}

void	ft_clear(t_format *ft)
{
	ft->width = 0;
	ft->flag = ' ';
	ft->precision = -1;
}

int		ft_format(const char *s, t_format *ft, va_list *args, int i)
{
	ft_clear(ft);
	if (s[i] == ' ')
	{
		ft_putchar_fd(' ', 1);
		while (s[i] == ' ')
			i++;
	}
	while (s[i] == '0' || s[i] == '-')
	{
		if (ft->flag != '-')
			ft->flag = s[i];
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		ft->width = ft->width * 10 + (s[i++] - 48);
	if (s[i] == '*')
	{
		if ((ft->width = va_arg(*args, int)) < 0)
		{
			ft->width *= -1;
			ft->flag = '-';
		}
		i++;
	}
	return (i + ft_useless(&s[i], ft, args, 0) + 1);
}
