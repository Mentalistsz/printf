#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_format
{
	int			flag;
	char		type;
	int			width;
	int			precision;
}				t_format;

int				ft_printf(const char *s, ...);

int				ft_format(const char *s, t_format *ft, va_list *args, int i);

int				ft_handler(t_format *ft, va_list *args);

int				ft_width(t_format *ft, char *s, int len, int out);

int				ft_type_id(t_format *ft, va_list *args, int i);

int				ft_type_u(t_format *ft, va_list *args);

int				ft_type_s(t_format *ft, va_list *args);

int				ft_precision(t_format *ft, char **s, int len);

int				ft_type_c(t_format *ft, va_list *args);

int				ft_type_x(t_format *ft, va_list *args);

int				ft_type_p(t_format *ft, va_list *args);

int				ft_putstr_fd(char *s, int fd);

int				ft_putchar_fd(char c, int fd);

size_t			ft_strlen(char *s);

char			*ft_itoa(int n);

char			*ft_utoa(unsigned int n);

char			*ft_substr(char *s, unsigned int start, size_t len);

#endif
