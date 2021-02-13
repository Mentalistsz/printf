#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_format	ft;
	int			i;
	int			out;

	i = 0;
	out = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if ((i += ft_format(&s[i + 1], &ft, &args, 0)) < 0)
				return (0);
			out += ft_handler(&ft, &args);
		}
		if (s[i] && s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
			out++;
		}
	}
	va_end(args);
	return (out);
}
