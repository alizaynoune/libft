#include "ft_dprintf.h"

void	_putformat(t_data *d)
{
	ft_putchar_fd(d->str[d->i++], d->fd);
	d->ret++;
}

void	_unkown(t_data *d)
{
	write(d->fd, "%", 1);
	(d->flag & _space) ? write(d->fd, " ", 1) : 0;
	(d->flag & _space) ? d->ret += 2: d->ret++;
}

void	read_format(t_data *d)
{
	size_t	cp;
	
	cp = ++d->i;
	if (d->str[d->i])
	{
		_flags(d);
		width_precision(d);
		_length(d);
		d->length ? cp = d->i : 0;
		_specifier(d);
		!(d->specif & _di) && !(d->specif & _p) ?\
			(d->flag -= (d->flag & _plus)) : 0;
		!(d->specif & _x) && !(d->specif & _X) && !(d->specif & _o) ?\
			(d->flag -= (d->flag & _hash)) : 0;
		(!(d->specif & _di) && !(d->specif & _p)) ||\
			(d->flag & _plus) ? (d->flag -= (d->flag & _space)) : 0;
		!d->specif && (d->i = cp) ? _unkown(d): get_arg(d);
	}
	else
		d->ret = -1;
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_data		*d;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		return (-1);
	ft_bzero(&d->wid_pre, sizeof(t_width_precision));
	d->str = format;
	d->fd = fd;
	va_start(d->ap, format);
	while (d->str[d->i] && d->ret != -1)
		d->str[d->i] == '%' ? read_format(d): _putformat(d);
	va_end(d->ap);
	free(d);
	return (d->ret);
}
