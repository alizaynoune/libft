#include "ft_dprintf.h"

void	_length(t_data *d)
{
	if (d->str[d->i] == 'l' || d->str[d->i] == 'h')
	{
		if (d->str[d->i] == 'l')
			d->str[d->i + 1] == 'l' ? d->length |= _ll :\
					  (d->length |= _l);
		else if (d->str[d->i] == 'h')
			d->str[d->i + 1] == 'h' ? d->length |= _hh :\
					  (d->length |= _h);
		(d->length & _ll) || (d->length & _hh) ? d->i += 2 : d->i++;
	}
}

size_t		_ato_unsint(const char *str)
{
	size_t		num;
	size_t		i;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	return (num);
}

void	width_precision(t_data *d)
{
	d->wid_pre.width = _ato_unsint(&d->str[d->i]);
	while (ft_isdigit(d->str[d->i]))
		d->i++;
	if (d->str[d->i] == '.')
	{
		d->flag |= _dot;
		d->i++;
		d->flag -= (d->flag & _zero);
	}
	d->wid_pre.precision = _ato_unsint(&d->str[d->i]);
	while (ft_isdigit(d->str[d->i]))
		d->i++;
	d->flag & _zero && d->flag & _left ? d->flag -= (d->flag & _zero) : 0;
}

void	_flags(t_data *d)
{
	while (d->str[d->i])
	{
		if (d->str[d->i] == '#')
			d->flag |= _hash;
		else if (d->str[d->i] == ' ')
			d->flag |= _space;
		else if (d->str[d->i] == '0')
			d->flag |= _zero;
		else if (d->str[d->i] == '-')
			d->flag |= _left;
		else if (d->str[d->i] == '+')
			d->flag |= _plus;
		else
			break ;
		d->i++;
	}
	
}

void	_specifier(t_data *d)
{
	d->str[d->i] == 's' || d->str[d->i] == 'S' ? d->specif |= _s : 0;
	d->str[d->i] == 'c' || d->str[d->i] == 'C'  ? d->specif |= _c : 0;
	d->str[d->i] == 'p' || d->str[d->i] == 'P' ? d->specif |= _p : 0;
	d->str[d->i] == 'i' || d->str[d->i] == 'd'  || d->str[d->i] == 'I' ||\
		      d->str[d->i] == 'D' ? d->specif |= _di : 0;
	d->str[d->i] == 'o' || d->str[d->i] == 'O' ? d->specif |= _o : 0;
	d->str[d->i] == 'u' || d->str[d->i] == 'U' ? d->specif |= _u : 0;
	d->str[d->i] == 'x' ? d->specif |= _x : 0;
	d->str[d->i] == 'X' ? d->specif |= _X : 0;
	d->str[d->i] == 'b' || d->str[d->i] == 'B' ? d->specif |= _b : 0;
	d->str[d->i] == '%' ? d->specif |= _MOD : 0;
	d->specif ? d->i++ : 0;
}


