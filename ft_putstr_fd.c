#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
