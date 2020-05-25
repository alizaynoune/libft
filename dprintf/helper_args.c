#include "ft_dprintf.h"

void	_octal(t_data *d)
{
	char	*s_;

	s_ = "01234567";
	!(d->length) ? _put_octal(d,\
			_base_str(d, va_arg(d->ap, unsigned int), s_, 8)) : 0;
	(d->length & _l) ? _put_octal(d, _base_str(d,\
				va_arg(d->ap, unsigned long int), s_, 8)) : 0;
	(d->length & _ll) ? _put_octal(d, _base_str(d,\
			va_arg(d->ap, unsigned long long int), s_, 8)) : 0;
	(d->length & _h) ? _put_octal(d, _base_str(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), s_, 8)) : 0;
	(d->length & _hh) ? _put_octal(d, _base_str(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), s_, 8)) : 0;
}

void	_binary(t_data *d)
{
	char	*s_;

	s_ = "01";
	!(d->length) ? _put_decimal(d, _base_str(d,\
				va_arg(d->ap, unsigned int), s_, 2)) : 0;
	(d->length & _l) ? _put_decimal(d, _base_str(d,\
				va_arg(d->ap, unsigned long int), s_, 2)) : 0;
	(d->length & _ll) ? _put_decimal(d, _base_str(d, va_arg(d->ap,\
					unsigned long long int), s_, 2)) : 0;
	(d->length & _h) ? _put_decimal(d, _base_str(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), s_, 2)) : 0;
	(d->length & _hh) ? _put_decimal(d, _base_str(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), s_, 2)) : 0;
}


