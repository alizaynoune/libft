#include "ft_dprintf.h"

void	_decimal(t_data *d)
{
	char	*str;

	str = NULL;
	!(d->length)? str = ft_itoa(va_arg(d->ap, int)) : 0;
	(d->length & _l) ? str = ft_ltoa(va_arg(d->ap, long int)) : 0;
	(d->length & _ll) ? str = ft_lltoa(va_arg(d->ap, long long int)) : 0;
	(d->length & _h) ? str = ft_itoa((short int)(va_arg(d->ap, int))) : 0;
	(d->length & _hh) ? str = ft_itoa((char)(va_arg(d->ap, int))) : 0;
	!str ? _exit_error(d) : 0;
	_put_decimal(d, str);
}

void	_unsigned(t_data *d)
{
	char	*str;
	!(d->length)? str = _unsigned_str(d, va_arg(d->ap, unsigned int)): 0;
	(d->length & _l) ? str = _unsigned_str(d,\
			va_arg(d->ap, unsigned long int)) : 0;
	(d->length & _ll) ? str = _unsigned_str(d, va_arg(d->ap,\
				unsigned long long int)) : 0;
	(d->length & _h) ? str = _unsigned_str(d,\
			(unsigned short int)(va_arg(d->ap, unsigned int))) : 0;
	(d->length & _hh) ? str = _unsigned_str(d,\
			(unsigned char)(va_arg(d->ap, unsigned int))) : 0;
	_put_decimal(d, str);
}

void	_helper_hexa(t_data *d)
{
	char	*S_;

	S_ = "0123456789ABCDEF";
	!(d->length) ? _put_hexa(d,\
			_base_str(d, va_arg(d->ap, unsigned int), S_, 16)) : 0;
	(d->length & _l) ? _put_hexa(d, _base_str(d,\
				va_arg(d->ap, unsigned long int), S_, 16)) : 0;
	(d->length & _ll) ? _put_hexa(d, _base_str(d, va_arg(d->ap,\
					unsigned long long int), S_, 16)) : 0;
	(d->length & _h) ? _put_hexa(d, _base_str(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), S_, 16)) : 0;
	(d->length & _hh) ? _put_hexa(d, _base_str(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), S_, 16)) : 0;
}

void	_hexa(t_data *d)
{
	char	*S_;

	S_ = "0123456789abcdef" ;
	d->specif & _p ? _put_hexa(d, _base_str(d, va_arg(d->ap,\
					unsigned long long int), S_, 16)) : 0;
	if (d->specif & _x)
	{
		!(d->length) ? _put_hexa(d, _base_str(d, va_arg(d->ap,\
						unsigned int), S_, 16)) : 0;
		(d->length & _l) ? _put_hexa(d, _base_str(d, va_arg(d->ap,\
					unsigned long int), S_, 16)) : 0;
		(d->length & _ll) ? _put_hexa(d, _base_str(d,\
			va_arg(d->ap, unsigned long long int), S_, 16)) : 0;
		(d->length & _h) ? _put_hexa(d, _base_str(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), S_, 16)) : 0;
		(d->length & _hh) ? _put_hexa(d, _base_str(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), S_, 16)) : 0;
	}
	else if (d->specif & _X)
		_helper_hexa(d);
}

void	get_arg(t_data *d)
{
	(d->specif & _MOD) ? loop_char(d, '%', 1) : 0;
	(d->specif & _s) ? _string(d, va_arg(d->ap, char *)) : 0;
	(d->specif & _c) ? _char(d, va_arg(d->ap, int)) : 0;
	(d->specif & _di) ? _decimal(d) : 0;
	(d->specif & _u) ? _unsigned(d) : 0;
	(d->specif & _x) || (d->specif & _X) || (d->specif & _p) ? _hexa(d) : 0;
	(d->specif & _o) ? _octal(d) : 0;
	(d->specif & _b) ? _binary(d): 0;
	reset_data(d);
}


