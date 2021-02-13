#include "ft_printf.h"

int		ft_xsize(unsigned int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_xtoa(t_format *ft, unsigned long long n)
{
	int				size;
	char			*s;
	char			*letters;

	if (ft->type == 'x')
		letters = "abcdef";
	else
		letters = "ABCDEF";
	size = ft_xsize(n);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (s);
	s[size--] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		if ((n % 16) >= 0 && (n % 16) <= 9)
			s[size--] = (n % 16) + 48;
		else
			s[size--] = letters[(n % 16) - 10];
		n /= 16;
	}
	return (s);
}

int		ft_width_x(t_format *ft, char *s, int len)
{
	int out;

	out = 0;
	if (len < ft->width)
	{
		if (ft->flag == '-')
		{
			out += ft_putstr_fd(s, 1);
			while (len < ft->width)
			{
				out += ft_putchar_fd(' ', 1);
				len++;
			}
			return (out);
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

int		ft_precision_x(t_format *ft, char **s, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * (ft->precision + 1))))
		return (0);
	temp[ft->precision] = '\0';
	while (i < (ft->precision - len))
		temp[i++] = '0';
	while (i < ft->precision)
	{
		temp[i] = (*s)[i - (ft->precision - len)];
		i++;
	}
	free(*s);
	*s = temp;
	return (1);
}

int		ft_type_x(t_format *ft, va_list *args)
{
	int					len;
	char				*s;
	unsigned long long	n;

	n = va_arg(*args, unsigned int);
	s = ft_xtoa(ft, n);
	len = ft_strlen(s);
	if (ft->precision >= 0 && ft->width > 0 && ft->flag == '0')
		ft->flag = ' ';
	if (ft->precision > len)
		if (!ft_precision_x(ft, &s, len))
			return (0);
	len = ft_strlen(s);
	if (ft->precision == 0 && n == 0)
		len = ft_width_x(ft, "", 0);
	else
		len = ft_width_x(ft, s, len);
	free(s);
	return (len);
}
