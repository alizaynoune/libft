#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define _c	1
# define _s	2
# define _p	4
# define _di	8
# define _o	16
# define _u	32
# define _x	64
# define _X	128
# define _MOD	256
# define _b	512

# define _h	1
# define _hh	2
# define _l	4
# define _ll	8

# define _left	1
# define _hash	2
# define _plus	4
# define _zero	8
# define _space	16
# define _dot	32

typedef struct			s_width_precision
{
	size_t			width;
	size_t			precision;
}				t_width_precision;

typedef struct			s_data
{
	va_list			ap;
	int			fd;
	const char		*str;
	size_t			len;
	size_t			i;
	int			ret;
	int			flag;
	short			specif;
	short			length;
	t_width_precision	wid_pre;
}				t_data;

int	ft_dprintf(int fd, const char *format, ...);
void	get_arg(t_data *d);
void	_flags(t_data *d);
void	width_precision(t_data *d);
void	_length(t_data *d);
void	_specifier(t_data *d);
void	_string(t_data *d, char *str);
void	_char(t_data *d, int c);
void	_octal(t_data *d);
void	_binary(t_data *d);
char	*_unsigned_str(t_data *d, unsigned long long int value);
char	*_base_str(t_data *d, unsigned long long int v, char *s_, size_t base);
void	_fix_len_decimal(t_data *d, char *str);
void	_fix_len_octal(t_data *d, char *str);
void	_fix_p(t_data *d, char **str);
void	loop_char(t_data *d, char c, int loop);
void	_put_hash(t_data *d);
void	_put_str(t_data *d, char *str);
void	_put_octal(t_data *d, char *str);
void	_put_decimal(t_data *d, char *str);
void	_put_decimal(t_data *d, char *str);
void	_put_flag(t_data *d, char c);
void	_put_hexa(t_data *d, char *str);
void	_exit_error(t_data *d);
void	reset_data(t_data *d);

#endif
