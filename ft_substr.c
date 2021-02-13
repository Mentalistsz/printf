#include "ft_printf.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	min;

	if (!s)
		return (NULL);
	min = ft_strlen(s);
	if (start > min)
	{
		start = min;
		min = 0;
	}
	if (min > len)
		min = len;
	i = 0;
	out = (char *)malloc(sizeof(char) * (min + 1));
	if (!out)
		return (NULL);
	while ((i < min) && s[i])
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}
