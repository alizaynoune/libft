#include "ft_dprintf.h"

void	_put_flag(t_data *d, char c)
{
	d->flag & _plus ? write(d->fd, "+", 1) : 0;
	d->flag & _space ? write(d->fd, " ", 1) : 0;
	c == '-' ? write(d->fd, "-", 1) : 0;
	d->ret++;
}

void	_put_hash(t_data *d)
{
	(d->specif & _x) || (d->specif & _p) ? _put_str(d, "0x") : 0;
	(d->specif & _X) ? _put_str(d, "0X") : 0;
}

void	_fix_len_decimal(t_data *d, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	str[0] == '-' ? len-- : 0;
	d->wid_pre.precision -= d->wid_pre.precision > len ?\
				len : d->wid_pre.precision;
	d->wid_pre.width -= d->wid_pre.width > (d->wid_pre.precision + len) ?\
			    (d->wid_pre.precision + len) : d->wid_pre.width;
}

void	_fix_len_octal(t_data *d, char *str)
{
	size_t		len;

	len = ft_strlen(str);
	d->wid_pre.precision -= d->wid_pre.precision > len ?\
				len : d->wid_pre.precision;
	d->wid_pre.precision && (d->flag & _hash) ? d->wid_pre.precision-- : 0;
	d->wid_pre.width -= d->wid_pre.width > (d->wid_pre.precision + len)\
			    ? (d->wid_pre.precision + len) : d->wid_pre.width;
}

void	_fix_p(t_data *d, char **str)
{
	if (*str[0] == '0')
	{
		d->wid_pre.precision = 0;
		d->flag -= (d->flag & _zero);
		d->flag -= (d->flag & _plus);
		d->flag -= (d->flag & _space);
		*str = "(nil)";
	}
	else
		d->flag |= _hash;
}


