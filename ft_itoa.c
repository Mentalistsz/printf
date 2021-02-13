#include "ft_printf.h"

int		ft_size(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*out;

	size = ft_size(n);
	if (!(out = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out[size--] = '\0';
	if (n == 0)
		out[0] = '0';
	if (n == -2147483648)
	{
		out[size--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		n = n * (-1);
		out[0] = '-';
	}
	while (n > 0)
	{
		out[size--] = ((n % 10) + 48);
		n /= 10;
	}
	return (out);
}

int		ft_usize(unsigned int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	int		size;
	char	*out;

	size = ft_usize(n);
	if (!(out = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out[size--] = '\0';
	if (n == 0)
		out[0] = '0';
	while (n > 0)
	{
		out[size--] = ((n % 10) + 48);
		n /= 10;
	}
	return (out);
}
