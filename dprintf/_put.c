#include "ft_dprintf.h"

void	_put_str(t_data *d, char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		write(d->fd, &str[i++], 1);
		d->ret++;
	}
}


void	loop_char(t_data *d, char c, int loop)
{
	while (loop > 0)
	{
		write(d->fd, &c, 1);
		d->ret++;
		loop--;
	}
}


void	_put_decimal(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(str[0] == '-') ? d->flag -= (d->flag & _space) : 0;
	(str[0] == '-') ? d->flag -= (d->flag & _plus) : 0;
	(d->flag & _dot) && str[0] == '0' ? str = "" : 0;
	_fix_len_decimal(d, str);
	d->wid_pre.width && (d->flag & _plus || d->flag & _space ||\
			str[0] == '-') ? d->wid_pre.width-- : 0;
	!(d->flag & _left) && !(d->flag & _zero) ?\
		loop_char(d, ' ', d->wid_pre.width) : 0;
	d->flag & _plus || d->flag & _space || str[0] == '-' ?\
						       _put_flag(d, str[0]) : 0;
	!(d->flag & _left) && (d->flag & _zero) ?\
		loop_char(d, '0', d->wid_pre.width) : 0;
	(d->wid_pre.precision) ? loop_char(d, '0', d->wid_pre.precision) : 0;
	str[0] == '-' ? str++ : 0;
	_put_str(d, str);
	(d->flag & _left) ? loop_char(d, ' ', d->wid_pre.width) : 0;
	free(ptr);
}

void	_put_octal(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(d->flag & _dot) && str[0] == '0' ? str = "" : 0;
	(str[0] == '0') ? d->flag -= (d->flag & _hash) : 0;
	_fix_len_octal(d, str);
	(d->flag & _hash) && d->wid_pre.width ? d->wid_pre.width-- : 0;
	!(d->flag & _left) && !(d->flag & _zero) ?\
		loop_char(d, ' ', d->wid_pre.width) : 0;
	(d->flag & _hash) ? loop_char(d, '0', 1) : 0;
	(d->wid_pre.precision) ? loop_char(d, '0', d->wid_pre.precision) : 0;
	!(d->flag & _left) && (d->flag & _zero) ?\
		loop_char(d, '0', d->wid_pre.width) : 0;
	_put_str(d, str);
	(d->flag & _left) ? loop_char(d, ' ', d->wid_pre.width) : 0;
	free(ptr);
}

void	_put_hexa(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(d->specif & _p) ? _fix_p(d, &str) : 0;
	(str[0] == '0') ? d->flag -= (d->flag & _hash) : 0;
	(d->flag & _dot) && str[0] == '0' ? str = "" : 0;
	_fix_len_decimal(d, str);
	if ((d->flag & _hash) && d->wid_pre.width >= 1)
		d->wid_pre.width -= d->wid_pre.width > 1 ? 2 : 1;
	(d->wid_pre.width) && ((d->flag & _plus) || (d->flag & _space))\
		? d->wid_pre.width-- : 0;
	!(d->flag & _left) && !(d->flag & _zero) ?\
		loop_char(d, ' ', d->wid_pre.width) : 0;
	if (d->specif & _p && ((d->flag & _space) || (d->flag & _plus)))
		(d->flag & _space) ?\
			loop_char(d, ' ', 1) : loop_char(d, '+', 1);
	(d->flag & _hash) ? _put_hash(d): 0;
	!(d->flag & _left) && (d->flag & _zero) ?\
		loop_char(d, '0', d->wid_pre.width) : 0;
	(d->wid_pre.precision) ? loop_char(d, '0', d->wid_pre.precision) : 0;
	_put_str(d, str);
	(d->flag & _left) ? loop_char(d, ' ', d->wid_pre.width) : 0;
	free(ptr);
}


